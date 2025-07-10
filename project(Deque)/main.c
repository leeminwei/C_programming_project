#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "deque.h"

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (nums == NULL || numsSize < k || k <= 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize - k + 1;

    //result整數陣列為最終輸出結果
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    int result_idx = 0;
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }
    //deque佇列存的是nums的idx
    Deque* dq = createDeque(k + 1);

    for (int i=0 ; i<numsSize ; i++) {

        while (isDequeEmpty(dq) == false && nums[i] >= nums[peek_back(dq)]) {
            pop_back(dq);
        }

        push_back(dq, i);

        if (isDequeEmpty(dq) == false && dq->data[dq->front] <= i-k) {
            pop_front(dq);
        }

        if (i >= k-1) {
            int value = peek_front(dq);
            result[result_idx++] = nums[value];
        }
    }
    // --- TODO: 請在此處填寫您的解題邏輯 ---
    //
    // 提示:
    // 遍歷 nums 陣列 (用 for 迴圈, i 從 0 到 numsSize-1)
    // 1. 維護一個單調遞減的 Deque (儲存索引)
    //    - 當 Deque 不為空且隊尾索引對應的值小於目前 nums[i] 時，pop_back()
    // 2. 將目前索引 i push_back() 到 Deque
    // 3. 如果隊首的索引已經滑出窗口 (dq->front <= i - k)，則 pop_front()
    // 4. 如果 i >= k - 1，表示窗口已形成，
    //    - 將隊首索引對應的值 (即當前窗口最大值) 存入 result 陣列
    //
    // ------------------------------------
    
    destroyDeque(dq);
    return result;
}

// Forward declaration
void run_test_case(int* nums, int numsSize, int k){
    printf("\n這是你輸入的資料\n");
    for (int i=0 ; i<numsSize ; i++) {
        printf("%d ", nums[i]);
    }
    printf("\nk = %d\n", k);
    int returnSize = 0;
    int* result = maxSlidingWindow(nums, numsSize, k, &returnSize);
    printf("\n這是你輸出的資料\n");
    for (int i=0 ; i<returnSize ; i++) {
        printf("%d ", result[i]);
    }
    printf("\n\n");
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 
 * 題目：滑動窗口最大值 (Sliding Window Maximum)
 * 
 * 給定一個長度為 n 的整數陣列 nums 和一個整數 k，
 * 請你找出所有長度為 k 的連續子陣列的最大值，並以陣列形式回傳這些最大值。
 * 
 * 解題提示：
 * 1. 建立一個 Deque，用來儲存 `nums` 陣列的「索引」。
 * 2. 遍歷 `nums` 陣列，對於每個元素 `nums[i]`:
 *    a. 當 Deque 不為空，且 Deque 尾部索引對應的 `nums` 值小於等於 `nums[i]` 時，
 *       表示尾部元素已不可能成為最大值，將其從尾部移除 (pop_back)。
 *    b. 將當前元素的索引 `i` 從尾部加入 Deque (push_back)。
 *    c. 檢查 Deque 頭部的索引是否已經滑出窗口範圍 (即 `peek_front() <= i - k`)，
 *       如果是，則從頭部移除 (pop_front)。
 *    d. 當遍歷的索引 `i` 到達 `k-1` (形成第一個完整窗口) 以後，
 *       每個窗口的最大值就是 Deque 頭部索引所對應的 `nums` 值。
 *       將 `nums[peek_front()]` 加入結果陣列。
 * 3. 最後回傳結果陣列。記得要設定 `*returnSize`。
 */


// --- 以下是測試與互動邏輯，請勿修改 ---

void print_array(const char* label, int* arr, int size) {
    printf("%s: [", label);
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void process_file_mode(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    printf("--- Running in File Mode (source: %s) ---\n\n", filename);

    int k, numsSize;
    int test_case_num = 1;
    while (fscanf(file, "%d %d", &k, &numsSize) == 2) {
        int* nums = (int*)malloc(sizeof(int) * numsSize);
        if (!nums) {
            printf("Failed to allocate memory for nums array.\n");
            break;
        }
        for (int i = 0; i < numsSize; ++i) {
            fscanf(file, "%d", &nums[i]);
        }

        printf("--- Test Case #%d ---\n", test_case_num++);
        run_test_case(nums, numsSize, k);
        free(nums);
    }

    fclose(file);
}

void process_interactive_mode() {
    printf("--- Running in Interactive Mode ---\n");
    int k, numsSize;
    
    printf("Enter window size (k): ");
    if (scanf("%d", &k) != 1 || k <= 0) {
        printf("Invalid k value. Exiting.\n");
        return;
    }

    printf("Enter number of elements in array (n): ");
    if (scanf("%d", &numsSize) != 1 || numsSize <= 0) {
        printf("Invalid array size. Exiting.\n");
        return;
    }

    int* nums = (int*)malloc(sizeof(int) * numsSize);
    if (!nums) {
        printf("Failed to allocate memory for nums array.\n");
        return;
    }
    
    printf("Enter %d integers for the array:\n", numsSize);
    for (int i = 0; i < numsSize; ++i) {
        scanf("%d", &nums[i]);
    }

    run_test_case(nums, numsSize, k);
    free(nums);
}


void print_usage(const char* prog_name) {
    printf("Usage: %s [test_file]\n", prog_name);
    printf("  - No arguments: Run in interactive mode.\n");
    printf("  - [test_file]: Run in file mode, reading test cases from the specified file.\n");
}

int main(int argc, char *argv[]) {
    if (argc > 2 || (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))) {
        print_usage(argv[0]);
        return 0;
    }

    if (argc == 2) {
        process_file_mode(argv[1]);
    } else {
        process_interactive_mode();
    }

    return 0;
} 