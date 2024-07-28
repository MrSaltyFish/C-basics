#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100  // Maximum size of the stack
#define MAX 5

typedef struct {
    int top;
    int items[MAXSTACK];
} Stack;

int graph[MAX][MAX] = {0};

void printGraph() {
    int i = 0;
    int j = 0;
    printf("\nAdjacency Matrix: ");
    printf("\n    1 2 3 4 5");
    printf("\n--------------\n");
    for(i = 0; i < MAX; i++) {
        printf("%d | ", i + 1);
        for(j = 0; j < MAX; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void findVertex(int vertex) {
    int i = vertex - 1;
    int j = 0;
    printf("\nVertex details for %d: <vertex>(<weight>)", i + 1);
    printf("\n%d => ", i + 1);
    for(j = 0; j < MAX; j++) {
        if(graph[i][j] != 0) {
            printf("%d(%d) ", j, graph[i + 1][j + 1]);
        }
    }
    printf("\n");
}

// Function to initialize the stack
void initializeStack(Stack *s) { s->top = -1; }

// Function to check if the stack is empty
bool isEmptyStack(Stack *s) { return s->top == -1; }

// Function to check if the stack is full
bool isFullStack(Stack *s) { return s->top == MAXSTACK - 1; }

// Function to push an element onto the stack
bool push(Stack *s, int item) {
    if(isFullStack(s)) {
        printf("Stack overflow\n");
        return false;
    }
    s->items[++(s->top)] = item;
    return true;
}

// Function to pop an element from the stack
bool pop(Stack *s, int *item) {
    if(isEmptyStack(s)) {
        printf("Stack underflow\n");
        return false;
    }
    *item = s->items[(s->top)--];
    return true;
}

// Function to peek at the top element of the stack
bool peek(Stack *s, int *item) {
    if(isEmptyStack(s)) {
        printf("Stack is empty\n");
        return false;
    }
    *item = s->items[s->top];
    return true;
}

typedef struct {
    int front, rear, size;
    int items[MAXSTACK];
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Function to check if the queue is empty
bool isEmptyQueue(Queue *q) { return q->size == 0; }

// Function to check if the queue is full
bool isFullQueue(Queue *q) { return q->size == MAXSTACK; }

// Function to enqueue an element to the queue
bool enqueue(Queue *q, int item) {
    if(isFullQueue(q)) {
        printf("Queue overflow\n");
        return false;
    }
    q->rear = (q->rear + 1) % MAXSTACK;
    q->items[q->rear] = item;
    q->size++;
    return true;
}

// Function to dequeue an element from the queue
bool dequeue(Queue *q, int *item) {
    if(isEmptyQueue(q)) {
        printf("Queue underflow\n");
        return false;
    }
    *item = q->items[q->front];
    q->front = (q->front + 1) % MAXSTACK;
    q->size--;
    return true;
}

// Function to get the front element of the queue
bool front(Queue *q, int *item) {
    if(isEmptyQueue(q)) {
        printf("Queue is empty\n");
        return false;
    }
    *item = q->items[q->front];
    return true;
}

void BFS(int arr[MAX][MAX], int visited[MAX], int start) {
    Queue q;
    initializeQueue(&q);
    for(int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }
    enqueue(&q, start);
    visited[0] = start;
    while(!isEmptyQueue(&q)) {
        int n = 0;
        dequeue(&q, &n);
        printf("%d ", n);
        for(int i = 0; i < MAX; i++) {
            if(arr[n][i] != 0 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(&q, arr[n][i]);
            }
        }
    }
}

int main() {
    int sourceVertex = -1;
    int destinationVertex = -1;
    int weight = 0;
    int visited[MAX] = {0};
    //------------------------Input---------------------------------------
    printf("Creating adjacency matrix:- ");
    do {
        printf("\nEnter data (-1 to end): ");
        printf("\nEnter source vertex: ");
        scanf("%d", &sourceVertex);
        printf("Enter destination vertex: ");
        scanf("%d", &destinationVertex);
        printf("Enter weight: ");
        scanf("%d", &weight);

        if(sourceVertex == -1 || destinationVertex == -1) {
            break;
        } else if(sourceVertex > MAX || destinationVertex > MAX ||
                  weight == 0) {
            printf("Invalid input for vertices. Please try again.\n%d\n%d\n%d",
                   sourceVertex, destinationVertex, weight);
        } else {
            if(graph[sourceVertex - 1][destinationVertex - 1] == 0) {
                graph[sourceVertex - 1][destinationVertex - 1] = weight;
                graph[destinationVertex - 1][sourceVertex - 1] = weight;
            } else {
                printf("\nAlready present in Graph.");
            }
        }
    } while(sourceVertex != -1 && destinationVertex != -1);

    //------------------------Output---------------------------------------
    BFS(graph, visited, 0);
    printf("\n");
    printGraph();
    findVertex(1);

    printf("program ended: ");
    scanf("%d", &weight);
    return 0;
}