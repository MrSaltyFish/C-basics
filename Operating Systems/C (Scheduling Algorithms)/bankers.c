#include <stdio.h>
#define MAX_PROCESSES 10
#define NO_OF_RESOURCES 3
int main() {
    int maximum_allocation_matrix[MAX_PROCESSES][NO_OF_RESOURCES];
    int allocated_matrix[MAX_PROCESSES][NO_OF_RESOURCES];
    int need_matrix[MAX_PROCESSES][NO_OF_RESOURCES];
    int available[NO_OF_RESOURCES];
    int safe_sequence[MAX_PROCESSES];
    int number_of_process;

    // MAX ALLOCATION MATRIX INPUT
    printf("Enter number of processes: ");
    scanf("%d", &number_of_process);
    printf("\nEnter maximumm resource allocation of each process:\n");
    for(int i = 0; i < MAX_PROCESSES; i++) {
        printf("\nDetails of process %d resources:\n", i + 1);
        for(int j = 0; j < NO_OF_RESOURCES; j++) {
            printf("Max of %c: ", j + 65);
            scanf("%d", &maximum_allocation_matrix[i][j]);
            printf("Allocated of %c: ", j + 65);
            scanf("%d", &allocated_matrix[i][j]);
        }
    }

    // NEED MATRIX
    for(int i = 0; i < number_of_process; i++) {
        for(int j = 0; j < NO_OF_RESOURCES; j++) {
            need_matrix[i][j] =
                maximum_allocation_matrix[i][j] - allocated_matrix[i][j];
        }
    }

    for(int i = 0; i < number_of_process; i++) {
        // need[i] is fixed1
        for(int j = 0; j < NO_OF_RESOURCES; j++) {
            for(int k = 0; k < NO_OF_RESOURCES; k++) {
            }
        }
    }

    // SAFE SEQUENCE -
    printf("The safe sequence is: \n");

    return 0;
}