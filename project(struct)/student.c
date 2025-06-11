#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#define MAX 1024
void print_student(const struct Student *s) {
    printf("id : %d\n",s->id);
    printf("姓名 : %s\n",s->name);
    printf("分數 : %f\n",s->score);
    printf("\n");
}

int read_students_from_file(const char *filename, struct Student students[], int max_students) {
    FILE *file;
    char buffer[MAX] = "";
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("open file error");
        return 0;
    }
    int student_index = 0;
    while (fgets(buffer, MAX, file) != NULL) {
        int len = strlen(buffer);
        buffer[len - 1] = '\0';
        char* token = strtok(buffer, ",");
        int token_index = 0;
        while(token != NULL) {
            if (token_index == 0) {
                students[student_index].id = atoi(token);
            }
            else if (token_index == 1) {
                strcpy(students[student_index].name, token);
            }
            else {
                students[student_index].score = atof(token);
                student_index++;
                token_index = 0;
            }
            token = strtok(NULL, ",");
            token_index++;
        }
    }
    return student_index;
}

void save_students_to_file(const char *filename, const struct Student students[], int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("寫入檔案失敗：%s\n", filename);
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%.2f\n", students[i].id, students[i].name, students[i].score);
    }
    fclose(file);
}

void add_student(struct Student students[], int *count, int max_students) {
    if (*count >= max_students) {
        printf("學生數已達上限，無法新增。\n");
        return;
    }
    struct Student s;
    printf("請輸入學生id : \n");
    scanf("%d", &s.id);
    while (getchar() != '\n'); 

    printf("請輸入學生姓名 : \n");
    scanf("%s",s.name);
    printf("請輸入學生成績 : \n");
    scanf("%lf",&s.score);
    while (getchar() != '\n'); 
    students[*count] = s;
    (*count)++;
}

void update_student(struct Student students[], int count) {
    int id;
    printf("請輸入要被更新的學生id : \n");
    scanf("%d", &id);
    while (getchar() != '\n'); 
    int found = -1;
    for (int i=0 ; i<count ; i++) {
        if (id == students[i].id) {
            found = i;
            printf("姓名 : %s\n",students[i].name);
            printf("成績 : %f\n",students[i].score);
            break;
        }
    }
    printf("請輸入要被更新的資料選項(姓名or成績) : \n");
    char choice[MAX] = "";
    scanf("%s", choice);
    if (strcmp(choice, "姓名") == 0) {
        char new_name[MAX] = "";
        printf("請輸入更新的名字 : \n");
        scanf("%s", new_name);
        strcpy(students[found].name, new_name);
    }
    else if (strcmp(choice, "成績") == 0) {
        double new_score = 0.0;
        printf("請輸入更新的成績 : \n");
        scanf("%lf", &new_score);
        while (getchar() != '\n'); 
        students[found].score = new_score;
    }
    else {
        printf("輸入錯誤");
    }
}

void delete_student(struct Student students[], int *count) {
    int id;
    printf("請輸入要刪除的學生id : \n");
    scanf("%d", &id);
    while (getchar() != '\n'); 
    //found用來記錄要被刪除的學生是誰
    int found = -1;

    for (int i=0 ; i<*count ; i++) {
        if (id == students[i].id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("找不到該學生，無法刪除。\n");
        return;
    }
    for (int i=0 ; i<*count ; i++) {
        if (found == i) {
            for(int j=i ; j<*count-1 ; j++) {
                students[j] = students[j+1];
            }
        }
    }
    (*count)--;
    printf("已成功刪除");
}