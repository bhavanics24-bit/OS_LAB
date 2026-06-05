#include<stdio.h>

int main() {
    int pages[20], frames[10], time[10];
    int n, f, i, j, pageFaults = 0, found, pos, min;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                time[j] = i;
            }
        }

        if(!found) {
            min = time[0];
            pos = 0;

            for(j = 1; j < f; j++) {
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            time[pos] = i;
            pageFaults++;
        }
    }

    printf("Page Faults = %d", pageFaults);
    return 0;
}
