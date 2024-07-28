#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Size of the queue

// Queue structure definition
struct CircularQueue {
    int arr[SIZE];  // Array to hold queue elements
    int front;      // Front index
    int rear;       // Rear index
};

void initQueue(struct CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct CircularQueue *queue) { return queue->front == -1; }

int isFull(struct CircularQueue *queue) {
    return ((queue->rear % SIZE) + 1) == (queue->front % SIZE);
}

// Function to enqueue (add) an element to the queue
void enqueue(struct CircularQueue *queue, int value) {
    if(isFull(queue)) {
        printf("\nCircular Queue is full. Cannot enqueue.\n");
        return;
    }
    if(isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    }
    queue->rear = ((queue->rear + 1) % SIZE);
    queue->arr[queue->rear] = value;
    printf("Enqueued element %d.\n", value);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct CircularQueue *queue) {
    if(isEmpty(queue)) {
        printf("\nCircular Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = queue->arr[queue->front];
    queue->front = ((queue->front + 1) % SIZE);
    printf("Dequeued element %d.\n", value);
    return value;
}

// Function to traverse the queue and perform an operation on each element
void traverseQueue(struct CircularQueue *queue) {
    if(isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    // Iterate through the queue from front to rear
    for(int i = queue->front; i <= queue->rear; i++) {
        // Perform the specified operation on each element
        printf("%d ", queue->arr[i]);
    }
}
void displayQueue(struct CircularQueue *queue) {
    if(isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue contents: ");
    // Traverse the queue from front to rear
    int i = queue->front;
    while(1) {
        printf("%d ", queue->arr[i]);
        if(i == queue->rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
void printMenu() {
    printf("1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Print top");
    printf("\n4. Traverse");
    printf("\n0. Exit");
}

int main() {
    struct CircularQueue queue;
    initQueue(&queue);
    int ele = 0;
    int loopCounter = 1;
    while(loopCounter) {
        printMenu();
        printf("\nEnter choice: ");
        scanf("%d", &loopCounter);

        switch(loopCounter) {
            case 1:
                printf("\nEnter element: ");
                scanf("%d", &ele);
                enqueue(&queue, ele);
                break;
            case 2:
                printf("%d\n\n", dequeue(&queue));
                break;
            case 4:
                printf("\nTraverse: ");
                displayQueue(&queue);
                printf("\n");
                break;
            case 0:
                exit(0);
                break;
        }
    }

    return 0;
}
