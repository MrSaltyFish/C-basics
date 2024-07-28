#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//=========== Assignment 6 ====================
int isEmpty(int* top) { return (*top == -1); }

char topElement(int* stack, int* top) { return stack[*top]; }

int isFull(int* top) { return (*top == MAX - 1); }

void push(int* stack, int* top, int ele) {
    if(isFull(top)) {
        printf("\nStack Overflow\n");
        return;
    }
    stack[++*top] = ele;
}

char pop(int* stack, int* top) {
    if(isEmpty(top)) {
        printf("\nStack Underflow\n");
        return -1;
    }
    *top = *top - 1;
    return stack[*top + 1];
}

void traverse(int* stack, int* top) {
    if(isEmpty(top)) {
        printf("\nStack Empty\n");
        return -1;
    }
    for(int i = 0; i <= *top; i++) {
        printf("%d ", stack[i]);
    }
}
void printMenu() {
    printf("1. Push");
    printf("\n2. Pop");
    printf("\n3. Print top");
    printf("\n4. Traverse");
    printf("\n0. Exit");
}
//===========================================

//=========== Assignment 7 ==================
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
            c == '=');
}

int isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void reverseString(char* str) {
    int length = strlen(str);
    for(int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    int i, j = 0;
    int length = strlen(infix);

    for(i = 0; i < length; i++) {
    }
}
//===========================================
int main() {
    char stack[MAX];
    int top = -1;
    int ele = 5;
    int loopCounter = 1;
    while(loopCounter) {
        printMenu();
        printf("\nEnter choice: ");
        scanf("%d", &loopCounter);

        switch(loopCounter) {
            case 1:
                printf("\nEnter element: ");
                scanf("%d", &ele);
                push(stack, &top, ele);
                break;
            case 2:
                printf("%d\n\n", pop(stack, &top));
                break;
            case 3:
                printf("\nTop: ");
                printf("%d", topElement(stack, &top));
                printf("\n");
                break;
            case 4:
                printf("\nTraverse: ");
                traverse(stack, &top);
                printf("\n");
                break;
            case 0:
                exit(0);
                break;
        }
    }
}