#include<stdio.h>

int main()
{
    int n, i;
    int weight[10], totalWeight = 0;
    float totalCPU, share;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter total CPU time: ");
    scanf("%f", &totalCPU);

    printf("Enter weights of processes:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
        totalWeight += weight[i];
    }

    printf("\nProcess\tWeight\tCPU Time\n");

    for(i = 0; i < n; i++)
    {
        share = (weight[i] * totalCPU) / totalWeight;
        printf("P%d\t%d\t%.2f\n", i + 1, weight[i], share);
    }

    return 0;
}
