#include <stdio.h>

int main() {
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int AT[n], BT[n], RT[n];
    int CT[n], TAT[n], WT[n];
    int visited[n];   // to track if added to queue

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for(int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i+1);
        scanf("%d %d", &AT[i], &BT[i]);
        RT[i] = BT[i];
        visited[i] = 0;
    }

    int queue[100], front = 0, rear = 0;

    int time = 0, done = 0;

    // Add first arriving processes at time 0
    for(int i = 0; i < n; i++) {
        if(AT[i] == 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while(done < n) {

        if(front == rear) {
            time++;
            // check for new arrivals
            for(int i = 0; i < n; i++) {
                if(!visited[i] && AT[i] <= time) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int i = queue[front++];

        if(RT[i] > tq) {
            time += tq;
            RT[i] -= tq;
        } else {
            time += RT[i];
            RT[i] = 0;

            CT[i] = time;
            TAT[i] = CT[i] - AT[i];
            WT[i] = TAT[i] - BT[i];

            done++;
        }

        // Add newly arrived processes during execution
        for(int j = 0; j < n; j++) {
            if(!visited[j] && AT[j] <= time) {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }

        // If process not finished, push back to queue
        if(RT[i] > 0) {
            queue[rear++] = i;
        }
    }

    // Averages
    float avgWT = 0, avgTAT = 0;

    for(int i = 0; i < n; i++) {
        avgWT += WT[i];
        avgTAT += TAT[i];
    }

    avgWT /= n;
    avgTAT /= n;

    // Output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
            i+1, AT[i], BT[i],
            CT[i], TAT[i], WT[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avgWT);
    printf("Average Turnaround Time = %.2f\n", avgTAT);

    return 0;
}
