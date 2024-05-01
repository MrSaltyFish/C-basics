#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int isEmpty(int* top) { return (*top == -1); }

int isFull(int* top) { return (*top == MAX - 1); }

void push(int* stack, int* top, int ele) {
    if(isFull(top)) {
        printf("\nStack Overflow\n");
        return;
    }
    stack[++*top] = ele;
}

int pop(int* stack, int* top) {
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
    printf("\n5. Exit");
}

int main() {
    int stack[MAX];
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
                printf("%d", stack[top]);
                printf("\n");
                break;
            case 4:
                printf("\nTraverse: ");
                traverse(stack, &top);
                printf("\n");
                break;
            case 5:
                exit(0);
                break;
        }
    }
}