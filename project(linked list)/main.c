#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1024

typedef struct listnode{
    int id;
    char name[MAX];
    int score;
    struct listnode *next;
}listnode;

void print_student(listnode* head) {
    for (listnode* cur = head; cur != NULL; cur = cur->next) {
        printf("id  : %d\n", cur->id);
        printf("姓名: %s\n", cur->name);
        printf("分數: %d\n\n", cur->score);
    }
}

listnode* read_students_from_file(const char* filename, listnode* head, int* max_student) {
    FILE* file;
    file = fopen(filename, "r");
    char buffer[MAX];
    if(file == NULL) {
        printf("cannot open file");
        return 0;
    }
    listnode* cur = (listnode*)malloc(sizeof(listnode));
    cur->next = NULL;
    head = cur;
    int count = 0;
    while(fgets(buffer, MAX, file) != NULL) {
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        listnode* new = (listnode*)malloc(sizeof(struct listnode));
        new->next = NULL;
        int status = 0;
        char* token;
        token = strtok(buffer, ",");
        while (token != NULL) {
            if(status == 0) {
                new->id = atoi(token);
            }
            else if(status == 1) {
                strcpy(new->name, token);
            }
            else {
                new->score = atoi(token);
            }
            token = strtok(NULL, ",");
            status++;
        }
        cur->next = new;
        cur = new;
        count++;
    }
    *max_student = count;
    cur->next = NULL;
    head = head->next;
    return head;
}

listnode* add_student(listnode* head, int *count, int max_students) {
    if (*count >= max_students) {
        printf("學生數已達上限，無法新增。\n");
        return head;
    }
    listnode* new = (listnode*)malloc(sizeof(listnode));
    new->next = NULL;
    printf("請輸入學生id : \n");
    scanf("%d", &new->id);
    while (getchar() != '\n');

    printf("請輸入學生姓名 : \n");
    scanf("%s",new->name);
    printf("請輸入學生成績 : \n");
    scanf("%d",&new->score);
    while (getchar() != '\n');
    listnode* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = new;
    return head;
}

void delete_student(listnode** head, int *count) {
    if (*head == NULL) {
        puts("目前沒有學生資料。");
        return;
    }
    int id;
    printf("請輸入要刪除的學生id : \n");
    scanf("%d", &id);
    while (getchar() != '\n'); 
    //found用來記錄要被刪除的學生是誰
    int found = -1;
    listnode* cur = *head;
    if(cur->id == id) {
        cur = cur->next;
        found = id;
        *head = (*head)->next;
        return;
    }
    while (cur->next != NULL) {
        if (cur->next->id == id) {
            cur->next = cur->next->next;
            found = id;
        }
        //如果cur->next接到NULL，就無法再執行cur = cur->next
        if (cur->next == NULL)
            break;
        cur = cur->next;
    }
    if (found == -1) {
        printf("找不到該學生，無法刪除。\n");
        return;
    }
    (*count)--;
    printf("已成功刪除");
    return;
}


void save_students_to_file(const char* filename, listnode* head) {
    FILE *file;
    file = fopen(filename,"w");
    if (file == NULL) {
        printf("寫入檔案失敗：%s\n", filename);
        return;
    }
    listnode* cur = head;
    while (cur != NULL) {
        //寫入檔案
        fprintf(file, "%d,%s,%d\n", cur->id, cur->name, cur->score);
        cur = cur->next;
    }

    //程式結束前閉檔
    fclose(file);
    return ;
}

void update_student(listnode* head, int count) {
    int id;
    printf("請輸入要被更新的學生id : \n");
    scanf("%d", &id);
    while (getchar() != '\n');
    listnode* cur = head;
    while (cur != NULL) {
        if (cur->id == id) {
            printf("請輸入要被更新的資料選項(姓名or成績) : \n");
            char choice[MAX] = "";
            scanf("%s", choice);
            if (strcmp(choice, "姓名") == 0) {
                char new_name[MAX] = "";
                printf("請輸入更新的名字 : \n");
                scanf("%s", new_name);
                strcpy(cur->name, new_name);
            }
            else if (strcmp(choice, "成績") == 0) {
                int new_score;
                printf("請輸入更新的成績 : \n");
                scanf("%d", &new_score);
                cur->score = new_score;
            }
            else {
                printf("輸入錯誤");
            }
            break;
        }
        cur = cur->next;
    }
}

int main() {
    int max_students = 0;
    listnode* head = NULL;
    head = read_students_from_file("students_data.txt", head, &max_students);
    printf("已載入 %d 筆學生資料。\n", max_students);
    int choice;
    while (1) {
        printf("\n====== 學生管理系統 ======\n");
        printf("1. 顯示所有學生\n");
        printf("2. 新增學生\n");
        printf("3. 刪除學生\n");
        printf("4. 更新學生資料\n");
        printf("5. 儲存並離開\n");
        printf("請輸入選項：");
        scanf("%d", &choice);
        while (getchar() != '\n'); 
        if (choice == 1) {
            if (max_students == 0) {
                printf("目前沒有學生資料。\n");
            } 
            else {
                print_student(head);
            }
        }
        else if (choice == 2) {
            add_student(head, &max_students, MAX);
        }
        
        else if (choice == 3) {
            delete_student(&head, &max_students);
        }
        else if (choice == 4) {
            update_student(head, max_students);
        }
        else if (choice == 5) {
            save_students_to_file("students_data.txt", head);
            printf("資料已儲存，程式結束。\n");
            break;
        }
        else {
            printf("無效選項，請重新輸入。\n");
        }
    }
    return 0;
}