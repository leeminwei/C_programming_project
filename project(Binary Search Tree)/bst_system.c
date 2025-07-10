#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "bst.h"


BST* createBST(){
    BST* tree = (BST*)malloc(sizeof(BST));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

TreeNode* createNode(int data){
    TreeNode* treenode = (TreeNode*)malloc(sizeof(TreeNode));
    treenode->data = data;
    treenode->left = NULL;
    treenode->right = NULL;
    return treenode;
}
/*
// 輔助函數聲明
TreeNode* findMinNode(TreeNode* root) {

}

TreeNode* findMaxNode(TreeNode* root){

}

TreeNode* insertNode(TreeNode* root, int data, bool* success){

}

TreeNode* deleteNode(TreeNode* root, int data, bool* success){

}
*/
bool isValidBSTHelper(TreeNode* root, int minVal, int maxVal){
    if (root == NULL) {
        return true;
    }
    bool left = isValidBSTHelper(root->left, minVal, maxVal);
    if (root->data > maxVal) {
        maxVal = root->data;
    }
    else{
        return false;
    }
    bool right = isValidBSTHelper(root->right, minVal, maxVal);
    return left && right;
}

bool insert(BST* bst, int data){

    //如果目前樹是空的
    if (bst->root == NULL) {
        TreeNode* treenode = createNode(data);
        bst->root = treenode;
        bst->size = 1;
        return true;
    }
    //如果樹不是空的
    TreeNode* cur = bst->root;
    while (cur != NULL) {

        if (data == cur->data) {
            return false;
        }
        else if (data < cur->data) {
            if (cur->left == NULL) {
                TreeNode* treenode = createNode(data);
                cur->left = treenode;
                bst->size++;
                return true;
            }
            cur = cur->left;
        }
        else {
            if (cur->right == NULL) {
                TreeNode* treenode = createNode(data);
                cur->right = treenode;
                bst->size++;
                return true;
            }
            cur = cur->right;
        }
    }
    return false;
}

bool deleteBST(BST* bst, int data){
    if (bst == NULL || bst->root == NULL) {
        printf("樹為空，無法刪除\n");
        return false;
    }

    TreeNode* cur = bst->root;
    TreeNode* parent = NULL;
    //用來Twochild = 用來判斷刪除的節點是否有兩個子結點
    bool Twochild = false;

    while (cur != NULL) {
        if (data == cur->data) {

            //如果要刪除的節點，left跟right都是NULL
            if (cur->left == NULL && cur->right == NULL) {
                if (parent == NULL) {
                    bst->root = NULL;  // or left/right/replace
                }
                else if (cur->data < parent->data) {
                    parent->left = NULL;
                    free(cur);
                }
                else{
                    parent->right = NULL;
                    free(cur);
                }
                return true;
            }

            //如果要刪除的節點，有一個左結點
            else if (cur->left != NULL && cur->right == NULL) {

                if (parent == NULL) {
                    bst->root = cur->left;
                    free(cur);
                }
                else if (cur->data < parent->data) {
                    parent->left = cur->left;
                    free(cur);
                }
                else{
                    parent->right = cur->left;
                    free(cur);
                }
                return true;
            }

            //如果要刪除的節點，有一個右結點
            else if (cur->left == NULL && cur->right != NULL) {

                if (parent == NULL) {
                    bst->root = cur->right;
                    free(cur);
                }
                else if (cur->data < parent->data) {
                    parent->left = cur->right;
                    free(cur);
                }
                else{
                    parent->right = cur->right;
                    free(cur);
                }
                return true;
            }

            //如果要刪除的節點，有兩個子結點
            else {
                Twochild = true;
                break;
            }
            
        }
        else if (data < cur->data) {
            parent = cur;
            cur = cur->left;
        }
        else{
            parent = cur;
            cur = cur->right;
        }
    }
    //如果有兩個子結點就要特殊處理(找右半部的最小值取代)
    if (Twochild == true) {

        //replace是用來存右半部最小結點的Node
        TreeNode* replace = cur->right;
        TreeNode* replace_parent = cur;

        while (replace->left != NULL) {
            replace_parent = replace;
            replace = replace->left;
        }

        //將當前的data用replace的data取代
        cur->data = replace->data;
        if (replace_parent == cur) {
            replace_parent->right = replace->right;
        }
        else {
            replace_parent->left = replace->right;
        }

        free(replace);
        return true;
    }

    return false;
}

TreeNode* findMinNode(TreeNode* root) {

    //如果樹為空
    if (root == NULL) {
        perror("樹是空的");
        return NULL;
    }
    //如果樹不是空的
    TreeNode* cur = root;
    while (cur->left != NULL) {
        cur = cur->left;
    }
    return cur;
}

int findMin(BST* bst){

    //如果樹為空
    if (bst->root == NULL) {
        perror("樹是空的");
        return -1;
    }

    //如果樹不是空的
    TreeNode* cur = bst->root;
    while (cur->left != NULL) {
        cur = cur->left;
    }
    return cur->data;
}

TreeNode* findMaxNode(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    TreeNode* cur = root;
    while (cur->right != NULL) {
        cur = cur->right;
    }
    return cur;
}

int findMax(BST* bst){

    //如果樹為空
    if (bst->root == NULL) {
        perror("樹是空的");
        return -1;
    }

    //如果樹不是空的
    TreeNode* cur = bst->root;
    while (cur->right != NULL) {
        cur = cur->right;
    }
    return cur->data;
}

// 遍歷函數聲明
void inorderTraversal(TreeNode* root){

    if (root->left != NULL) {
        inorderTraversal(root->left);
    }

    printf("%d ", root->data);

    if (root->right != NULL) {
        inorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode* root){

    printf("%d ", root->data);

    if (root->left != NULL) {
        preorderTraversal(root->left);
    }

    if (root->right != NULL) {
        preorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode* root){

    
    if (root->left != NULL) {
        postorderTraversal(root->left);
    }

    if (root->right != NULL) {
        postorderTraversal(root->right);
    }

    printf("%d ", root->data);
}

// 佇列操作函數聲明
Queue* createQueue(void) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

bool isQueueEmpty(Queue* queue){
    if (queue->rear == NULL) {
        return true;
    }
    return false;
}

void enqueue(Queue* queue, TreeNode* treeNode){
    //如果佇列是空的
    if (isQueueEmpty(queue) == true) {
        QueueNode* queuenode = (QueueNode*)malloc(sizeof(QueueNode));
        queuenode->treeNode = treeNode;
        queuenode->next = NULL;
        queue->front = queuenode;
        queue->rear = queuenode;
        return;
    }
    //如果佇列不是空的
    QueueNode* queuenode = (QueueNode*)malloc(sizeof(QueueNode));
    queuenode->treeNode = treeNode;
    queuenode->next = NULL;
    queue->rear->next = queuenode;
    queue->rear = queuenode;
    return;
}

TreeNode* dequeue(Queue* queue){
    //如果佇列是空的
    if (isQueueEmpty(queue)) {
        return NULL;
    }

    //如果佇列只有一個元素
    if (queue->front == queue->rear) {
        TreeNode* pop_tree = queue->front->treeNode;
        free(queue->front);
        queue->front = NULL;
        queue->rear = NULL;
        return pop_tree;
    }

    //如果佇列有多個元素
    TreeNode* pop_tree = queue->front->treeNode;
    QueueNode* toRemove = queue->front; 
    queue->front = queue->front->next;
    free(toRemove);
    return pop_tree;
}


void freeQueue(Queue* queue){
    if (isQueueEmpty(queue)) {
        return;
    }
    QueueNode* cur = queue->front;
    while (cur != NULL) {
        QueueNode* queue_remove = cur;
        cur = cur->next;
        free(queue_remove);
    }
    free(queue);
    return;
}

void levelOrderTraversal(TreeNode* root){
    if (root == NULL) {
        return;
    }
    Queue* queue = createQueue();
    enqueue(queue, root);
    int* order_sorting = (int*)malloc(1000 * sizeof(int));
    int order_idx = 0;
    while (isQueueEmpty(queue) == false) {

        //size = 紀錄queue當前的元素數量
        QueueNode* cur = queue->front;
        int size = 0;
        while (cur != NULL) {
            size++;
            cur = cur->next;
        }
        //需要pop的次數就是前面size的數量(同層級的數量)
        while (size!=0) {
            TreeNode* pop_tree = dequeue(queue);
            order_sorting[order_idx++] = pop_tree->data;
            size--;
            if (pop_tree->left != NULL) {
                enqueue(queue, pop_tree->left);
            }
            if (pop_tree->right!= NULL) {
                enqueue(queue, pop_tree->right);
            }
        }
    }
    order_sorting = (int*)realloc(order_sorting, (order_idx)*sizeof(int));
    for (int i=0 ; i<order_idx ; i++) {
        printf("%d ", order_sorting[i]);
    }
    printf("\n");
    freeQueue(queue);
}

// 進階功能函數聲明
int calculateHeight(TreeNode* root){
    if (root == NULL) {
        return -1;
    }

    Queue* queue = createQueue();
    enqueue(queue, root);

    //level = 用來計算樹的高度
    int level = -1;

    while (isQueueEmpty(queue) == false) {

        //size = 紀錄queue當前的元素數量
        QueueNode* cur = queue->front;
        int size = 0;
        while (cur != NULL) {
            size++;
            cur = cur->next;
        }
        //需要pop的次數就是前面size的數量(同層級的數量)
        while (size!=0) {
            TreeNode* pop_tree = dequeue(queue);
            size--;
            if (pop_tree->left != NULL) {
                enqueue(queue, pop_tree->left);
            }
            if (pop_tree->right!= NULL) {
                enqueue(queue, pop_tree->right);
            }
        }
        level++;
    }
    return level;
}

bool isValidBST(TreeNode* root){
    return isValidBSTHelper(root, INT_MAX, INT_MIN);
}

void printspace(int num){
    for(int i =0 ; i<num ; i++){
        printf(" ");
    }
    return;
}

void displayTree(TreeNode* root, int level){
    if (root == NULL) {
        return;
    }
    printf("\n樹的結構\n");
    Queue* queue = createQueue();
    enqueue(queue, root);
    int cur_level = 0;
    while (isQueueEmpty(queue) == false && cur_level <= level) {

        //size = 紀錄queue當前的元素數量
        QueueNode* cur = queue->front;
        int size = 0;
        while (cur != NULL) {
            size++;
            cur = cur->next;
        }
        int front_space =  pow(2, level - cur_level) - 1;
        int word_space = pow(2, level - cur_level +1 ) - 1;
        printspace(front_space);
        //需要pop的次數就是前面size的數量(同層級的數量)
        while (size!=0) {

            TreeNode* pop_tree = dequeue(queue);
            size--;
            if (pop_tree != NULL) {
                printf("%2d", pop_tree->data);
                enqueue(queue, pop_tree->left);
                enqueue(queue, pop_tree->right);
            } else {
                printf("  ");
                enqueue(queue, NULL);
                enqueue(queue, NULL);
            }
            printspace(word_space);
        }
        printf("\n");
        cur_level++;
    }
    freeQueue(queue);
}

void clearTree(BST* bst){
    if (bst == NULL) return;
    freeTree(bst->root);
    bst->root = NULL;
    bst->size = 0;
}

void freeTree(TreeNode* root){
    if (root == NULL) return;
    if (root->left != NULL) {
        freeTree(root->left);
    }

    if (root->right != NULL) {
        freeTree(root->right);
    }

    TreeNode* toRemove = root;
    free(toRemove);
}

int main(){
    BST* bst = createBST();
    int choice;
    int level;
    while(1){
        printf("\n=== 二元搜尋樹系統 ===\n");
        printf("1. 插入節點\n");
        printf("2. 刪除節點\n");
        printf("3. 搜尋最小值\n");
        printf("4. 搜尋最大值\n");
        printf("5. 中序遍歷\n");
        printf("6. 前序遍歷\n");
        printf("7. 後序遍歷\n");
        printf("8. 層序遍歷\n");
        printf("9. 計算樹的高度\n");
        printf("10. 檢查BST有效性\n");
        printf("11. 顯示樹的結構\n");
        printf("12. 清空樹\n");
        printf("0. 結束程式\n");
        printf("請選擇操作：\n");
        scanf("%d", &choice);
        if (choice == 0) {
            exit(0);
        }
        else if (choice == 1) {
            printf("請輸入要插入的數值\n");
            int insert_data;
            scanf("%d", &insert_data);
            bool check = insert(bst, insert_data);
            if (check == true) {
                 printf("插入完畢\n");
            }
            else {
                printf("重複值, 無法插入\n");
            }
        }
        else if (choice == 2) {
            printf("\n請輸入要刪除的節點 : \n");
            int data;
            scanf("%d", &data);
            deleteBST(bst, data);
        }
        else if (choice == 3) {
            int min = findMin(bst);
            if (min != -1) {
                printf("最小值 = %d\n", min);
            }
        }
        else if (choice == 4) {
            int max = findMax(bst);
            if (max != -1) {
                printf("最大值 = %d\n", max);
            }
        }
        else if (choice == 5) {
            inorderTraversal(bst->root);
            printf("\n輸出中序排列\n");
        }
        else if (choice == 6) {
            preorderTraversal(bst->root);
            printf("\n輸出前序排列\n");
        }
        else if (choice == 7) {
            postorderTraversal(bst->root);
            printf("\n輸出後序排列\n");
        }
        else if (choice == 8) {
            levelOrderTraversal(bst->root);
            printf("\n輸出層序排列\n");
        }
        else if (choice == 9) {
            level = calculateHeight(bst->root);
            if (level == -1) {
                printf("樹是空的\n");
            }
            else{
                printf("樹的高度為 : %d\n", level);
            }
        }
        else if (choice == 10) {
            bool valid = isValidBST(bst->root);
            if (valid == true) {
                printf("樹有效\n");
            }
            else{
                printf("樹無效\n");
            }
        }
        else if (choice == 11) {
            displayTree(bst->root, level);
        }
        else if (choice == 12) {
            clearTree(bst);
            printf("清空完畢\n");
        }
        
        else {
            printf("輸入錯誤\n");
        }
    }
    return 0;
}
