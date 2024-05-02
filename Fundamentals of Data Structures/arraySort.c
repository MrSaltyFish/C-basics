#include <stdio.h>
#include <stdlib.h>
#define M 5
#define N 4

void traverse(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}

//============ Assignment 1 ===============
void mergeArrays(int* arrayA, int* arrayB, int* mergedArray, int* a, int* b,
                 int* m) {
    while(a < M && b < N) {
        if(arrayA[*a] < arrayB[*b]) {
            mergedArray[*m++] = arrayA[*a++];
        } else if(arrayA[*a] > arrayB[*b]) {
            mergedArray[*m++] = arrayB[*b++];
        } else {
            mergedArray[*m++] = arrayA[*a++];
            b++;
        }
    }
    while(a < M) {
        mergedArray[*m++] = arrayA[*a++];
    }
    while(b < N) {
        mergedArray[*m++] = arrayB[*b++];
    }
}
//---------------------------------
void intersectArrays(int* arrayA, int* arrayB, int* intersectionArray, int* a,
                     int* b, int* i) {
    while(a < M && b < N) {
        if(arrayA[*a] > arrayB[*b]) {
            b++;
        } else if(arrayA[*a] < arrayB[*b]) {
            a++;
        } else {
            intersectionArray[*i++] = arrayA[*a++];
            b++;
        }
    }
}
//=================================
// Assignment 4
void selectionSort(int* arr, int length) {
    int i = 0;
    for(int i = 0; i < length; i++) {
        for(int j = i; j < length; j++) {
            if(arr[i] > arr[j]) {
                int swap = arr[i];
                arr[i] = arr[j];
                arr[j] = swap;
            }
        }
    }
}
//=================================
int main() {
    int arrayA[M] = {5, 4, 3, 2, 1};
    int arrayB[N] = {6, 7, 8, 8};
    int mergedArray[M + N];
    int intersectionArray[M > N ? N : M];
    selectionSort(arrayA, M);
    selectionSort(arrayB, N);
    int a = 0;
    int b = 0;
    int m = 0;
    int i = 0;
    //=========== Merge ===============
    mergeArrays(arrayA, arrayB, mergedArray, &a, &b, &m);
    //=========== Intersection ============
    a = 0;
    b = 0;
    intersectArrays(arrayA, arrayB, intersectionArray, &a, &b, &i);
    printf("\nArrayA: ");
    traverse(arrayA, M);
    printf("\nArrayB: ");
    traverse(arrayB, N);
    printf("\nmergedArray: ");
    traverse(mergedArray, m);
    printf("\nintersectionArray: ");
    traverse(intersectionArray, i);
    getchar();
}