#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

// 定義學生結構
// struct 是一種複合資料型別，可以將不同型別的變數組合成一個單一的實體。
// 這裡，我們用它來表示一位學生，包含學號、姓名和分數。
struct Student {
    int id;
    char name[50];
    double score;
};

// 函式原型宣告

/**
 * @brief 印出單一學生的資料
 * 
 * @param s 指向 Student 結構的指標
 */
void print_student(const struct Student *s);

/**
 * @brief 從檔案中讀取學生資料
 * 
 * @param filename 要讀取的檔名
 * @param students 儲存學生資料的陣列
 * @param max_students 陣列的最大容量
 * @return int 實際讀取的學生數量
 */
int read_students_from_file(const char *filename, struct Student students[], int max_students);
/**
 * @brief 將所有學生資料儲存回檔案
 * 
 * @param filename 要寫入的檔名
 * @param students 存有學生資料的陣列
 * @param count 要寫入的學生數量
 */
void save_students_to_file(const char *filename, const struct Student students[], int count);

/**
 * @brief 在陣列中新增一位學生
 * 
 * @param students 學生陣列
 * @param count 指向目前學生數量的指標
 * @param max_students 陣列最大容量
 */
void add_student(struct Student students[], int *count, int max_students);

/**
 * @brief 根據學號更新學生資料
 * 
 * @param students 學生陣列
 * @param count 目前的學生數量
 */
void update_student(struct Student students[], int count);

/**
 * @brief 根據學號刪除一位學生
 * 
 * @param students 學生陣列
 * @param count 指向目前學生數量的指標
 */
void delete_student(struct Student students[], int *count);

#endif // STUDENT_H 