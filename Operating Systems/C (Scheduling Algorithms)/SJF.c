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
    //  SORTING ALGORITHM FOR BURST TIME
    for(i = 0; i < n; i++) {
        for(j = i; j < n; j++) {
            if(burstTime[i] > burstTime[j]) {
                int swap = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = swap;
            }
        }
    }
    // SAME AS FCFS----------------------------------------

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

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i = 0; i < n; i++) {
        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d", i + 1, burstTime[i],
               waitingTime[i], turnaroundTime[i]);
    }
    printf("\nAverage Waiting Time= %f", avgWaitingTime);
    printf("\nAverage Turnaround Time= %f", avgTurnaroundTime);

    return 0;
}