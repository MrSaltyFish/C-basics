#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Size of the queue

// Queue structure definition
struct Queue {
    int arr[SIZE];  // Array to hold queue elements
    int front;      // Front index
    int rear;       // Rear index
};

// Function to initialize the queue
void initQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) { return (queue->front == -1); }

// Function to check if the queue is full
int isFull(struct Queue *queue) { return (queue->rear == SIZE - 1); }

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue *queue, int value) {
    if(isFull(queue)) {
        printf("Queue is full. Cannot enqueue element %d.\n", value);
        return;
    }

    // If the queue is initially empty, set the front index to 0
    if(isEmpty(queue)) {
        queue->front = 0;
    }

    // Increment the rear index and add the element
    queue->rear++;
    queue->arr[queue->rear] = value;

    printf("Enqueued element %d.\n", value);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue *queue) {
    if(isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    // Retrieve the front element
    int value = queue->arr[queue->front];

    // Increment the front index
    queue->front++;

    // If the front index exceeds the rear, reset the queue to empty
    if(queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }

    printf("Dequeued element %d.\n", value);
    return value;
}

// Function to traverse the queue and perform an operation on each element
void traverseQueue(struct Queue *queue) {
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

void printMenu() {
    printf("1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Print top");
    printf("\n4. Traverse");
    printf("\n0. Exit");
}

int main() {
    struct Queue queue;
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
                traverseQueue(&queue);
                printf("\n");
                break;
            case 0:
                exit(0);
                break;
        }
    }

    return 0;
}
