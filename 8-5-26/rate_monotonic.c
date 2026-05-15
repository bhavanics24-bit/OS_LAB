#include<stdio.h>
#include<math.h>

int main()
{
    int n, i, hp = 0;
    float e[20], p[20];
    float ut = 0, u;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    // Input execution time and period
    for(i = 0; i < n; i++)
    {
        printf("\nEnter Execution Time for P%d: ", i + 1);
        scanf("%f", &e[i]);

        printf("Enter Period/Deadline for P%d: ", i + 1);
        scanf("%f", &p[i]);
    }

    // Calculate total utilization
    for(i = 0; i < n; i++)
    {
        ut += e[i] / p[i];
    }

    // Find highest priority process
    // Smaller period => Higher priority
    for(i = 1; i < n; i++)
    {
        if(p[i] < p[hp])
        {
            hp = i;
        }
    }

    // RMS schedulability bound
    u = n * (pow(2.0, 1.0 / n) - 1);

    printf("\n----------------------------------");
    printf("\nNumber of Processes = %d", n);

    printf("\nHighest Priority Process = P%d", hp + 1);

    printf("\nTotal Utilization = %.3f", ut);

    printf("\nRMS Bound = %.3f", u);

    // Schedulability check
    if(ut <= u)
    {
        printf("\nThe System is surely Schedulable");
    }
    else
    {
        printf("\nSchedulability is Not Guaranteed");
    }

    printf("\n----------------------------------");

    return 0;
}
