#include "deque.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief 建立一個新的 Deque。
 * 
 * 任務：
 * 1. 配置 Deque 結構所需的記憶體。
 * 2. 配置儲存資料的陣列 (data) 所需的記憶體。
 * 3. 初始化 Deque 的所有成員 (front, rear, size, capacity)。
 *    - front 可以初始化為 0 或 -1，取決於您的實作策略。
 *    - rear 初始化為 0。
 *    - size 初始化為 0。
 * 4. 回傳建立好的 Deque 指標。
 */
Deque* createDeque(int capacity) {
    // TODO: 實作此函式
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->data = (int*)malloc(capacity * sizeof(int));
    deque->front = 0;
    deque->rear = 0;
    deque->size = 0;
    deque->capacity = capacity;
    return deque;
}

/**
 * @brief 銷毀一個 Deque 並釋放其佔用的記憶體。
 * 
 * 任務：
 * 1. 釋放儲存資料的陣列 (data) 的記憶體。
 * 2. 釋放 Deque 結構本身的記憶體。
 */
void destroyDeque(Deque* dq) {
    // TODO: 實作此函式
    free(dq->data);
    free(dq);
}

/**
 * @brief 檢查 Deque 是否為空。
 */
bool isDequeEmpty(Deque* dq) {
    // TODO: 實作此函式
    // front = rear
    if (dq->size == 0) {
        return true;
    }
    return false;
}

/**
 * @brief 檢查 Deque 是否已滿。
 */
bool isDequeFull(Deque* dq) {
    // TODO: 實作此函式
    // (rear+1) % capacity = front
    if (dq->size == dq->capacity) {
        return true;
    }
    return false;
}

/**
 * @brief 從 Deque 的尾部新增一個元素。
 * 
 * 任務：
 * 1. 檢查 Deque 是否已滿。
 * 2. 將元素存入 rear 指向的位置。
 * 3. 更新 rear 指標，注意環形陣列的邊界情況 (取模運算)。
 * 4. 更新 size。
 */
void push_back(Deque* dq, int value) {
    // TODO: 實作此函式
    if (isDequeFull(dq) == true) {
        printf("佇列已滿, 無法插入\n");
        return;
    }

    dq->data[dq->rear] = value;
    dq->rear = (dq->rear + 1) % dq->capacity;
    dq->size++;
    return;
}

/**
 * @brief 從 Deque 的頭部新增一個元素。
 * 
 * 任務：
 * 1. 檢查 Deque 是否已滿。
 * 2. 更新 front 指標，注意環形陣列的邊界情況 (處理負數索引)。
 * 3. 將元素存入新的 front 指向的位置。
 * 4. 更新 size。
 */
void push_front(Deque* dq, int value) {
    // TODO: 實作此函式
    if (isDequeFull(dq) == true) {
        printf("佇列已滿, 無法插入\n");
        return;
    }
    dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    dq->data[dq->front] = value;
    dq->size++;
    return;
}

/**
 * @brief 從 Deque 的尾部移除一個元素。
 * 
 * 任務：
 * 1. 檢查 Deque 是否為空。
 * 2. 更新 rear 指標。
 * 3. 取得要被移除的元素。
 * 4. 更新 size。
 * 5. 回傳元素。
 */
int pop_back(Deque* dq) {
    // TODO: 實作此函式
    if (isDequeEmpty(dq) == true) {
        return -1;
    }
    dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    int pop_value = dq->data[dq->rear];
    dq->size--;
    return pop_value;
}

/**
 * @brief 從 Deque 的頭部移除一個元素。
 * 
 * 任務：
 * 1. 檢查 Deque 是否為空。
 * 2. 取得要被移除的元素。
 * 3. 更新 front 指標。
 * 4. 更新 size。
 * 5. 回傳元素。
 */
int pop_front(Deque* dq) {
    // TODO: 實作此函式
    if (isDequeEmpty(dq) == true) {
        return -1;
    }
    int pop_value = dq->data[dq->front];
    dq->front = (dq->front + 1) % dq->capacity;
    dq->size--;
    return pop_value;
}

/**
 * @brief 查看 Deque 的尾部元素，但不移除它。
 */
int peek_back(Deque* dq) {
    // TODO: 實作此函式
    if (isDequeEmpty(dq) == true) {
        return -1;
    }
    int last_index = (dq->rear - 1 + dq->capacity) % dq->capacity;
    int value = dq->data[last_index];
    return value;
}

/**
 * @brief 查看 Deque 的頭部元素，但不移除它。
 */
int peek_front(Deque* dq) {
    // TODO: 實作此函式
    if (isDequeEmpty(dq) == true) {
        return -1;
    }
    int value = dq->data[dq->front];
    return value;
} 