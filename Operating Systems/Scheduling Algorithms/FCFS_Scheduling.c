#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberOfProcesses;
    printf("Enter the number of processes: ");
    scanf("%d", &numberOfProcesses);
    int processesArr[numberOfProcesses][2];

    for (int i = 0; i < numberOfProcesses; i++)
    {
        printf("Enter arrival time for process %d: ", (i + 1));
        scanf("%d", &processesArr[i][0]);
        printf("Enter CPU burst time for process %d: ", (i + 1));
        scanf("%d", &processesArr[i][1]);
    }

    // Print the array
    for (size_t i = 0; i < numberOfProcesses; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            printf("%d ", processesArr[i][j]);
        }
        printf("\n");
    }
}
