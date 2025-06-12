#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef struct Node{
    int id;
    char bookname[MAX];
    char author[MAX];
    int time;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct DoubleLinkedList{
    struct Node* head;
    struct Node* tail;
    int size;
}DoubleLinkedList;

Node* createBookNode(int bookID, const char* title, const char* author) {
    Node* newbook = (Node*)malloc(sizeof(Node));
    newbook->id = bookID;
    strcpy(newbook->bookname, title);
    strcpy(newbook->author, author);
    newbook->time = 0;
    newbook->next = NULL;
    newbook->prev = NULL;
    return newbook;
}
void borrowBook(DoubleLinkedList* borrowedListHead) {
    
    //建立要添加的書籍資訊
    int id;
    char bookname[MAX];
    char author[MAX];
    printf("請輸入要被添加的ID資訊 : \n");
    scanf("%d",&id);
    Node* checkexist = borrowedListHead->head;
    while (checkexist != NULL) {
        if(checkexist->id == id) {
            checkexist->time++;
            return;
        }
        checkexist = checkexist->next;
        if (checkexist == borrowedListHead->head) {
            break;
        }
    }
    printf("請輸入要被添加的書名資訊 : \n");
    scanf("%s",bookname);
    printf("請輸入要被添加的作者資訊 : \n");
    scanf("%s",author);

    //newbook代表要被加入已借閱書籍的書
    Node* newbook = createBookNode(id, bookname, author);
    newbook->time++;

    DoubleLinkedList* cur = borrowedListHead;
    //如果已借閱書籍清單是空的
    if (borrowedListHead->head == NULL) {
        borrowedListHead->head = newbook;
        borrowedListHead->tail = newbook;
        borrowedListHead->size++;
        newbook->next = newbook;
        newbook->prev = newbook;
    }
    else {
        borrowedListHead->tail->next = newbook;
        newbook->next = borrowedListHead->head;
        borrowedListHead->head->prev = newbook;
        newbook->prev = borrowedListHead->tail;
        borrowedListHead->tail = newbook;
        borrowedListHead->size++;
    }
}
void returnBook(DoubleLinkedList* borrowedListHead) {
    int id;
    printf("請輸入要清除的書籍id\n");
    scanf("%d", &id);
    if(borrowedListHead->head == NULL){
        printf("已借閱書籍清單是空的\n");
        return;
    }
    Node* cur = borrowedListHead->head;
    if (borrowedListHead->head->id == id) {
        if(borrowedListHead->head == borrowedListHead->tail){
            free(cur);
            borrowedListHead->head = NULL;
            borrowedListHead->tail = NULL;
            borrowedListHead->size = 0;
            return;
        }
        borrowedListHead->tail->next = borrowedListHead->head->next;
        borrowedListHead->head = borrowedListHead->head->next;
        borrowedListHead->head->prev = borrowedListHead->tail;
        borrowedListHead->size--;
        free(cur);
        return;
    }
    if (borrowedListHead->tail->id == id) {
        cur = borrowedListHead->tail;
        borrowedListHead->tail = cur->prev;
        borrowedListHead->tail->next = borrowedListHead->head;
        borrowedListHead->head->prev = borrowedListHead->tail;
        borrowedListHead->size--;
        free(cur);
        return;
    }
    cur = cur->next;
    while (cur != borrowedListHead->tail) {
        if (cur->id == id) {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            free(cur);
            borrowedListHead->size--;
            return;
        }
        cur = cur->next;
    }
    printf("該id不存在\n");
}
void updateHotBooks(DoubleLinkedList* hotListHead, DoubleLinkedList* borrowedBook, int hotListCapacity) {
    if (borrowedBook->head == NULL) {
        printf("沒有已借閱書籍\n");
        return;
    }
    Node* cur = borrowedBook->head;
    while (cur != NULL) {
        if (cur->time >= hotListCapacity) {
            Node* newbook = createBookNode(cur->id, cur->bookname, cur->author);
            //如果熱門書籍清單是空的
            if (hotListHead->head == NULL) {
                hotListHead->head = newbook;
                hotListHead->tail = newbook;
                hotListHead->size++;
            }
            //如果熱門書籍清單不是空的
            else {
                hotListHead->tail->next = newbook;
                newbook->prev = hotListHead->tail;
                hotListHead->tail = newbook;
                hotListHead->size++;
                //如果熱門書籍清單超過容量限制
                if (hotListHead->size > hotListCapacity) {
                    Node* toRemove = NULL;
                    toRemove = hotListHead->head;
                    hotListHead->head = hotListHead->head->next;
                    free(toRemove);
                }
            }
        }
        cur = cur->next;
        if (cur == borrowedBook->head) {
            break;
        }
    }
    printf("更新完成\n");
}
void displayBorrowedBooks(DoubleLinkedList* borrowedListHead) {
    Node* cur = borrowedListHead->head;
    if(borrowedListHead->head == NULL){
        printf("已借閱書籍清單是空的\n");
        return;
    }
    while (cur != NULL) {
        printf("ID : %d\n", cur->id);
        printf("書名 : %s\n", cur->bookname);
        printf("作者 : %s\n", cur->author);
        printf("被借閱的次數 : %d\n", cur->time);
        printf("\n");
        cur = cur->next;
        if (cur == borrowedListHead->head) {
            break;
        }
    }
}


void displayHotBooks(DoubleLinkedList* hotListHead) {
    if (hotListHead->head == NULL) {
        return;
    }
    Node* cur = hotListHead->head;
    while (cur != NULL) {
        printf("ID : %d\n", cur->id);
        printf("書名 : %s\n", cur->bookname);
        printf("作者 : %s\n", cur->author);
        printf("\n");
        cur = cur->next;
    }
}
void cleanList(DoubleLinkedList* list){
    Node* cur = list->head;
    if(cur == NULL){
        free(list);
        return;
    }
    Node* toRemove = NULL;
    do{
        toRemove = cur;
        cur = cur->next;
        free(toRemove);
    }while(cur != NULL && cur != list->head);
    free(list);
}

int main() {
    //初始化 "已借閱書籍串列"
    DoubleLinkedList* borrowedlist = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    borrowedlist->head = NULL;
    borrowedlist->tail = NULL;
    borrowedlist->size = 0;

    //初始化 "熱門書籍串列"
    DoubleLinkedList* hotlist = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    hotlist->head = NULL;
    hotlist->tail = NULL;
    hotlist->size = 0;
    int hotListCapacity = 2;
    int choice;

    while (1) {
        printf("\n====== 圖書館管理系統 ======\n");
        printf("1. 顯示已借閱書籍清單\n");
        printf("2. 顯示熱門書籍清單\n");
        printf("3. 添加已借閱書籍\n");
        printf("4. 刪除已借閱書籍\n");
        printf("5. 更新熱門書籍清單\n");
        printf("6: 結束程式並清理環境\n");
        printf("請輸入選項：");
        scanf("%d", &choice);
        while (getchar() != '\n'); 
        if (choice == 1) {
            displayBorrowedBooks(borrowedlist);
        }
        else if (choice == 2) {
            displayHotBooks(hotlist);
        }
        
        else if (choice == 3) {
            borrowBook(borrowedlist);
        }
        else if (choice == 4) {
           returnBook(borrowedlist);
        }
        else if (choice == 5) {
            updateHotBooks(hotlist, borrowedlist, hotListCapacity);
        }
        else if (choice == 6){
            break;
        }
        else {
            printf("無效選項，請重新輸入。\n");
        }
    }
    cleanList(borrowedlist);
    cleanList(hotlist);
    printf("已成功清理環境並退出!\n");
    return 0;
}