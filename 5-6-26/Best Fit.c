#include <stdio.h>

int main()
{
    int m, n, i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    int block[m];
    printf("Enter block sizes:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int process[n], allocation[n];

    printf("Enter process sizes:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    for(i = 0; i < n; i++)
    {
        int best = -1;

        for(j = 0; j < m; j++)
        {
            if(block[j] >= process[i])
            {
                if(best == -1 || block[j] < block[best])
                    best = j;
            }
        }

        if(best != -1)
        {
            allocation[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t", i + 1, process[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
