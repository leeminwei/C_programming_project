#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#define MAX 1024

int main() {
    int max_students = 0;
    struct Student students[MAX];
    max_students = read_students_from_file("students.txt", students, MAX);
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
                for (int i = 0; i < max_students; i++) {
                    print_student(&students[i]);
                }
            }
        } else if (choice == 2) {
            add_student(students, &max_students, MAX);
        } else if (choice == 3) {
            delete_student(students, &max_students);
        } else if (choice == 4) {
            update_student(students, max_students);
        } else if (choice == 5) {
            save_students_to_file("students.txt", students, max_students);
            printf("資料已儲存，程式結束。\n");
            break;
        } else {
            printf("無效選項，請重新輸入。\n");
        }
    }
    return 0;
}