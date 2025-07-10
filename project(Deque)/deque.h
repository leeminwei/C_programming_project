#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>

// Deque 結構定義
// 我們使用環形陣列 (Circular Array) 來實作
typedef struct {
    int *data;      // 儲存元素的陣列
    int front;      // 指向隊首的索引
    int rear;       // 指向隊尾之後一個位置的索引
    int size;       // 目前儲存的元素數量
    int capacity;   // 陣列的總容量
} Deque;

/**
 * @brief 建立一個新的 Deque。
 * 
 * @param capacity Deque 的最大容量。
 * @return Deque* 成功時回傳指向新 Deque 的指標，失敗時回傳 NULL。
 */
Deque* createDeque(int capacity);

/**
 * @brief 銷毀一個 Deque 並釋放其佔用的記憶體。
 * 
 * @param dq 指向要銷毀的 Deque 的指標。
 */
void destroyDeque(Deque* dq);

/**
 * @brief 檢查 Deque 是否為空。
 * 
 * @param dq 指向 Deque 的指標。
 * @return bool 如果為空回傳 true，否則回傳 false。
 */
bool isDequeEmpty(Deque* dq);

/**
 * @brief 檢查 Deque 是否已滿。
 * 
 * @param dq 指向 Deque 的指標。
 * @return bool 如果已滿回傳 true，否則回傳 false。
 */
bool isDequeFull(Deque* dq);

/**
 * @brief 從 Deque 的尾部新增一個元素。
 * 
 * @param dq 指向 Deque 的指標。
 * @param value 要新增的元素值。
 */
void push_back(Deque* dq, int value);

/**
 * @brief 從 Deque 的頭部新增一個元素。
 * 
 * @param dq 指向 Deque 的指標。
 * @param value 要新增的元素值。
 */
void push_front(Deque* dq, int value);

/**
 * @brief 從 Deque 的尾部移除一個元素。
 * 
 * @param dq 指向 Deque 的指標。
 * @return int 移除的元素值。如果 Deque 為空，行為未定義。
 */
int pop_back(Deque* dq);

/**
 * @brief 從 Deque 的頭部移除一個元素。
 * 
 * @param dq 指向 Deque 的指標。
 * @return int 移除的元素值。如果 Deque 為空，行為未定義。
 */
int pop_front(Deque* dq);

/**
 * @brief 查看 Deque 的尾部元素，但不移除它。
 * 
 * @param dq 指向 Deque 的指標。
 * @return int 尾部元素的值。如果 Deque 為空，行為未定義。
 */
int peek_back(Deque* dq);

/**
 * @brief 查看 Deque 的頭部元素，但不移除它。
 * 
 * @param dq 指向 Deque 的指標。
 * @return int 頭部元素的值。如果 Deque 為空，行為未定義。
 */
int peek_front(Deque* dq);

#endif // DEQUE_H 