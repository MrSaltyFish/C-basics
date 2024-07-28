#include <stdio.h>
#define MAX_1 10
#define MAX_2 10

void swap(int *a, int *b) {
    int swap = *a;
    *a = *b;
    *b = swap;
}

//============ Sorting ===============
void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        int min = arr[i];
        int min_index = -1;
        for(int j = i; j < size - 1; j++) {
            if(arr[j] < min) {
                min = arr[j];
                min_index = j;
            }
        }
        if(arr[i] > min) {
            swap(&arr[i], &arr[min_index]);
        }
    }
}

void insertionSort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while(arr[j] > key && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//============ Printing ===============
void traverse(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printFunction(int arr1[], int arr2[]) {
    printf("Arr-1: ");
    traverse(arr1, MAX_1);
    printf("Arr-2: ");
    traverse(arr2, MAX_2);
}

//============ Main ===============
int main() {
    int arr1[MAX_1] = {23, 45, 12, 89, 34, 56, 78, 90, 11, 67};
    int arr2[MAX_2] = {54, 76, 19, 83, 41, 62, 38, 74, 29, 95};

    printFunction(arr1, arr2);
    bubbleSort(arr1, MAX_1);
    insertionSort(arr2, MAX_2);
    printf("\n");
    printFunction(arr1, arr2);
    return 0;
}