#include<stdio.h>

int main() {
    int pages[20], frames[10];
    int n, f, i, j, k, pos, farthest;
    int pageFaults = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++)
            if(frames[j] == pages[i])
                found = 1;

        if(!found) {
            pos = -1;
            farthest = i;

            for(j = 0; j < f; j++) {
                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k])
                        break;
                }

                if(k == n) {
                    pos = j;
                    break;
                }

                if(k > farthest) {
                    farthest = k;
                    pos = j;
                }
            }

            frames[pos == -1 ? 0 : pos] = pages[i];
            pageFaults++;
        }
    }

    printf("Page Faults = %d", pageFaults);
    return 0;
}
