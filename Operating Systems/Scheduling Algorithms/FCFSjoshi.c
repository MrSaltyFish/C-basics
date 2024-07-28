#include <stdio.h>

int main() {
    int n, burstTime[30];
    int waitingTime[30], turnaroundTime[30];
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    int i, j;
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

    for(i = 1; i < n; i++) {
        waitingTime[i] = 0;
        for(j = 0; j < i; j++) {
            waitingTime[i] += burstTime[j];
        }
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i = 0; i < n; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d", i + 1, burstTime[i],
               waitingTime[i], turnaroundTime[i]);
    }

    avgWaitingTime /= i;
    avgTurnaroundTime /= i;  // average calculation is done here
    printf("\nAverage Waiting Time: %d", avgWaitingTime);
    printf("\nAverage Turnaround Time: %d", avgTurnaroundTime);

    return 0;
}