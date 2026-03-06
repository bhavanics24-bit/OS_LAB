#include <stdio.h>
int main(){
  int n;

  printf("Enter number of processes:");
  scanf("%d",&n);
  int AT[n],BT[n],WT[n],TAT[n],CT[n];

  for(int i=0;i<n;i++){
    printf(" Arrival time of process %d:",i+1);
    scanf("%d",&AT[i]);
    printf(" Burst time of process %d:",i+1);
    scanf("%d",&BT[i]);
  }

  for(int i=0;i<n;i++){
    CT[i]=CT[i-1]+BT[i];
  }



  for(int i=0;i<n;i++){
    TAT[i]=CT[i]-AT[i];

  }

  for(int i=0;i<n;i++){
    WT[i]=TAT[i]-BT[i];
    if(WT[i]<0){
        WT[i]=0;
    }
    printf("%d\n",WT[i]);

  }

  int sum_of_WT=0;
  int sum_of_TAT=0;

  for(int i=0;i<n;i++){
    sum_of_WT+=WT[i];
    sum_of_TAT+=TAT[i];
  }

  float averageWT=(float)sum_of_WT/n;
  float averageTAT=(float)sum_of_TAT/n;
  printf("average waiting time:%f\n",averageWT);
  printf("average total turnaround time:%f",averageTAT);
  return 0;
}

