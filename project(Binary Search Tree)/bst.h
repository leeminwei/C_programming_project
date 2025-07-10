#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// 樹節點結構
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 二元搜尋樹結構
typedef struct {
    TreeNode* root;
    int size;
} BST;

// 基本操作函數聲明
BST* createBST(void);
TreeNode* createNode(int data);
bool insert(BST* bst, int data);
bool deleteBST(BST* bst, int data);
int findMin(BST* bst);
int findMax(BST* bst);

// 遍歷函數聲明
void inorderTraversal(TreeNode* root);
void preorderTraversal(TreeNode* root);
void postorderTraversal(TreeNode* root);
void levelOrderTraversal(TreeNode* root);

// 進階功能函數聲明
int calculateHeight(TreeNode* root);
bool isValidBST(TreeNode* root);
void displayTree(TreeNode* root, int level);
void clearTree(BST* bst);
void freeTree(TreeNode* root);

// 輔助函數聲明
TreeNode* findMinNode(TreeNode* root);
TreeNode* findMaxNode(TreeNode* root);
TreeNode* insertNode(TreeNode* root, int data, bool* success);
TreeNode* deleteNode(TreeNode* root, int data, bool* success);
bool isValidBSTHelper(TreeNode* root, int minVal, int maxVal);

// 使用者介面函數聲明
void displayMenu(void);
void handleUserInput(BST* bst);
int getIntInput(void);
void clearInputBuffer(void);

// 佇列結構（用於層序遍歷）
typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// 佇列操作函數聲明
Queue* createQueue(void);
void enqueue(Queue* queue, TreeNode* treeNode);
TreeNode* dequeue(Queue* queue);
bool isQueueEmpty(Queue* queue);
void freeQueue(Queue* queue);

#endif // BST_H 