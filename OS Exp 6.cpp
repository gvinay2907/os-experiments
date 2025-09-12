#include <stdio.h>
#define MAX 10

int main() {
    int n, i, j, time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[MAX], priority[MAX], rt[MAX], completedFlag[MAX] = {0}, wt[MAX], tat[MAX];
    printf("Enter Burst Time and Priority (lower number = higher priority):\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &bt[i], &priority[i]);
        rt[i] = bt[i];
    }

    while (completed != n) {
        int idx = -1, highestPriority = 9999;
        for (i = 0; i < n; i++) {
            if (completedFlag[i] == 0 && priority[i] < highestPriority && rt[i] > 0) {
                highestPriority = priority[i];
                idx = i;
            }
        }

        if (idx != -1) {
            rt[idx]--;
            time++;

            if (rt[idx] == 0) {
                completed++;
                completedFlag[idx] = 1;
                tat[idx] = time;
                wt[idx] = tat[idx] - bt[idx];
            }
        } else {
            time++;  // Idle time
        }
    }

    printf("\nPID\tBT\tPriority\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t\t%d\t%d\n", i + 1, bt[i], priority[i], wt[i], tat[i]);

    return 0;
}
