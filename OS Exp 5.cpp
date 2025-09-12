#include <stdio.h>

struct process {
    int pid, bt, priority, wt, tat;
};

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Burst Time and Priority for Process %d: ", i + 1);
        scanf("%d %d", &p[i].bt, &p[i].priority);
    }

    // Sort by priority (lower number = higher priority)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].wt = 0;
    p[0].tat = p[0].bt;
    for (i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }

    printf("\nPID\tBT\tPriority\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].bt, p[i].priority, p[i].wt, p[i].tat);

    return 0;
}
