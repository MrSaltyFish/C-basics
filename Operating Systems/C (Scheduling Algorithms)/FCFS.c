#include <stdio.h>

int main() {
    int n, i, j;
    int burstTime[30], waitingTime[30], turnaroundTime[30];
    float avgWaitingTime = 0, avgTurnaroundTime = 0;

    printf("Please enter the total number of processes(maximum 30): ");
    // the maximum process that be used to calculate is specified.
    scanf("%d", &n);

    printf("\nEnter The Process Burst Time: \n");
    for(i = 0; i < n; i++)
    // burst time for every process will be taken as input
    {
        printf("P[%d]:", i + 1);
        scanf("%d", &burstTime[i]);
    }

    waitingTime[0] = 0;

    // WAITING TIME FOR EACH PROCESS IS CALCULATED
    for(i = 1; i < n; i++) {
        waitingTime[i] = 0;
        for(j = 0; j < i; j++) {
            waitingTime[i] += burstTime[j];
        }
    }
    // TURNAROUNDTIME FOR EACH
    for(i = 0; i < n; i++) {
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }
    // AVERAGES FOR EACH
    avgWaitingTime = avgWaitingTime / n;
    avgTurnaroundTime = avgTurnaroundTime / n;

    return 0;
}