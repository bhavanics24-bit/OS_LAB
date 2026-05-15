#include <stdio.h>

int main()
{
    int n, m;

    // n = number of processes
    // m = number of resource types
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input Maximum Matrix
    printf("\nEnter Maximum Matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }

    // Calculate Need Matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\nNeed Matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    int finish[n], safeSeq[n];

    for(int i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;

    while(count < n)
    {
        int found = 0;

        for(int p = 0; p < n; p++)
        {
            // Check if process is unfinished
            if(finish[p] == 0)
            {
                int j;

                // Check if all resources can be allocated
                for(j = 0; j < m; j++)
                {
                    if(need[p][j] > avail[j])
                        break;
                }

                // If all needs can be satisfied
                if(j == m)
                {
                    for(int k = 0; k < m; k++)
                    {
                        avail[k] += alloc[p][k];
                    }

                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        // No process could be allocated
        if(found == 0)
        {
            printf("\nSystem is NOT in Safe State!\n");
            return 0;
        }
    }

    // Safe sequence exists
    printf("\nSystem is in SAFE STATE\n");
    printf("Safe Sequence: ");

    for(int i = 0; i < n; i++)
    {
        printf("P%d", safeSeq[i]);

        if(i != n - 1)
            printf(" -> ");
    }

    printf("\n");

    return 0;
}
