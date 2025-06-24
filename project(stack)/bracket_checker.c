#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX 1000

typedef struct ArrayStack{
    char data[MAX];
    int top;
}ArrayStack;

bool isEmpty(ArrayStack* stack){
    if (stack->top == -1) {
        return true;
    }
    return false;
}

bool isFull(ArrayStack* stack){
    if (stack->top == MAX-1) {
        return true;
    }
    return false;
}

void push(ArrayStack* stack, char input){
    if (isFull(stack) == true) {
        printf("堆疊已滿\n");
        return;
    }
    stack->data[++stack->top] = input;
}

void pop(ArrayStack* stack){
    if (isEmpty(stack) == true) {
        printf("堆疊為空\n");
        return;
    }
    stack->data[stack->top--];
    return;
}

ArrayStack* createStack() {
     ArrayStack* stack = (ArrayStack*)malloc(sizeof(ArrayStack));
     if (stack != NULL) {
        stack->top = -1;
     }
     return stack;
}

void runtest(char* input){
        
        if (input[strlen(input)-1] == '\n') {
            input[strlen(input)-1] = '\0';
        }
        int len = strlen(input);
        if (strcmp(input, "quit") == 0) {
            exit(0);
        }
        printf("檢查表達式 : %s\n", input);

        
        printf("長度 : %d\n", len);

        //建立堆疊
        ArrayStack* stack;
        stack = createStack();

        //判斷
        for (int i=0 ; i<len ; i++) {

            //如果一開始就是右半部
            if (i==0 && input[i] == ')') {
                printf("遇到右小括號 ')' - 錯誤：沒有對應的左括號\n");
            }
            else if (i==0 && input[i] == ']') {
                printf("遇到右中括號 ']' - 錯誤：沒有對應的左括號\n");
            }
            else if (i==0 && input[i] == '}') {
                printf("遇到右大括號 '}' - 錯誤：沒有對應的左括號\n");
            }
            //如果是左半部
            if (input[i] == '(') {
                printf("位置 %d : 遇到左小括號'(' , 推入Stack\n", i);
                push(stack, input[i]);
            }
            if (input[i] == '[') {
                printf("位置 %d : 遇到左中括號'[' , 推入Stack\n", i);
                push(stack, input[i]);
            }
            if (input[i] == '{') {
                printf("位置 %d : 遇到左大括號'{' , 推入Stack\n", i);
                push(stack, input[i]);
            }

            //如果是右半部且匹配
            if (input[i] == ')' && stack->data[stack->top] == '(') {
                printf("位置 %d : 遇到右小括號')' - 正確匹配左小括號 '('\n", i);
                pop(stack);
            }
            //如果是右半部但不匹配
            else if (input[i] == ')' && stack->data[stack->top] != '(') {
                if (stack->data[stack->top] == '[') {
                    printf("位置 %d : 遇到右小括號')' - 錯誤：與左中括號 '[' 不匹配\n", i);
                }
                else{
                    printf("位置 %d : 遇到右小括號')' - 錯誤：與左大括號 '{' 不匹配\n", i);
                }
                
            }
            //如果是右半部且匹配
            if (input[i] == ']' && stack->data[stack->top] == '[') {
                printf("位置 %d : 遇到右中括號']' - 正確匹配左中括號 '['\n", i);
                pop(stack);
            }
            //如果是右半部但不匹配
            else if (input[i] == ']' && stack->data[stack->top] != '[') {
                if (stack->data[stack->top] == '(') {
                    printf("位置 %d : 遇到右中括號']' - 錯誤：與左小括號 '(' 不匹配\n", i);
                }
                else{
                    printf("位置 %d : 遇到右中括號']' - 錯誤：與左大括號 '{' 不匹配\n", i);
                }
            }
            //如果是右半部且匹配
            if (input[i] == '}' && stack->data[stack->top] == '{') {
                printf("位置 %d : 遇到右大括號'}' - 正確匹配左大括號 '{'\n", i);
                pop(stack);
            }
            //如果是右半部但不匹配
            else if (input[i] == '}' && stack->data[stack->top] != '{') {
                if (stack->data[stack->top] == '(') {
                    printf("位置 %d : 遇到右大括號'}' - 錯誤：與左小括號 '(' 不匹配\n", i);
                }
                else{
                    printf("位置 %d : 遇到右大括號'}' - 錯誤：與左中括號 '[' 不匹配\n", i);
                }
            }
        }
        if (stack->top != -1) {
            printf("還有未匹配的左括號 : %s\n", stack->data);
        }
}

void readfile(const char* filename){
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("讀檔失敗\n");
        return;
    }
    char buffer[MAX];
    while (fgets(buffer, MAX, file) != NULL) {
        printf("\n");
        if (buffer[0] == '#') {
            continue;
        }
        int filelen = strlen(buffer);
        buffer[filelen - 1] = '\0';
        char* token;
        int token_idx = 0;
        token = strtok(buffer, "|");
        
        while (token != NULL) {
            if (token_idx == 0) {
                runtest(token);
            }
            else if (token_idx == 1) {
                printf("預期結果 : %s\n", token);
            }
            else if (token_idx == 2) {
                printf("說明 : %s\n", token);
            }
            token = strtok(NULL, "|");
            token_idx++;
        }
    }
}

int main(){

    readfile("test_data.txt");
    while(1){
        //讀取使用者的輸入
        char input[MAX];
        printf("\n=== 測試案例 ===\n");
        printf("請輸入要檢查的表達式\n");
        fgets(input, MAX, stdin);
        runtest(input);
    }
    return 0;
}