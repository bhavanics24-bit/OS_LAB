#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int AT[n], BT[n], P[n];

    for(i = 0; i < n; i++) {
        printf("Enter AT, BT, Priority for P%d: ", i+1);
        scanf("%d %d %d", &AT[i], &BT[i], &P[i]);
    }

    /* ========= NON-PREEMPTIVE PRIORITY ========= */

    int CT1[n], TAT1[n], WT1[n], done[n];
    int time = 0, completed = 0;
    float totalWT1 = 0, totalTAT1 = 0;

    for(i = 0; i < n; i++)
        done[i] = 0;

    while(completed < n) {
        int index = -1, minP = 9999;

        for(i = 0; i < n; i++) {
            if(AT[i] <= time && done[i] == 0 && P[i] < minP) {
                minP = P[i];
                index = i;
            }
        }

        if(index == -1) {
            time++;
        } else {
            CT1[index] = time + BT[index];
            time = CT1[index];

            TAT1[index] = CT1[index] - AT[index];
            WT1[index] = TAT1[index] - BT[index];

            totalWT1 += WT1[index];
            totalTAT1 += TAT1[index];

            done[index] = 1;
            completed++;
        }
    }

    printf("\n--- NON-PREEMPTIVE PRIORITY ---\n");
    printf("PID\tAT\tBT\tP\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, AT[i], BT[i], P[i], CT1[i], TAT1[i], WT1[i]);
    }

    printf("Average WT = %.2f\n", totalWT1/n);
    printf("Average TAT = %.2f\n", totalTAT1/n);


    /* ========= PREEMPTIVE PRIORITY ========= */

    int RT[n], CT2[n], TAT2[n], WT2[n];
    float totalWT2 = 0, totalTAT2 = 0;

    time = 0;
    completed = 0;

    for(i = 0; i < n; i++)
        RT[i] = BT[i];

    while(completed < n) {
        int index = -1, minP = 9999;

        for(i = 0; i < n; i++) {
            if(AT[i] <= time && RT[i] > 0 && P[i] < minP) {
                minP = P[i];
                index = i;
            }
        }

        if(index == -1) {
            time++;
        } else {
            RT[index]--;
            time++;

            if(RT[index] == 0) {
                CT2[index] = time;
                completed++;

                TAT2[index] = CT2[index] - AT[index];
                WT2[index] = TAT2[index] - BT[index];

                totalWT2 += WT2[index];
                totalTAT2 += TAT2[index];
            }
        }
    }

    printf("\n--- PREEMPTIVE PRIORITY ---\n");
    printf("PID\tAT\tBT\tP\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, AT[i], BT[i], P[i], CT2[i], TAT2[i], WT2[i]);
    }

    printf("Average WT = %.2f\n", totalWT2/n);
    printf("Average TAT = %.2f\n", totalTAT2/n);

    return 0;
}
