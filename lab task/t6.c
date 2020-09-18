#include<stdio.h>
//sjf preemptive
int main()
{
  int time,bt[10],at[10],sum_bt=0,smallest,n,i;
  int sumt=0,sumw=0,tat,wt;
  printf("Enter the no of processes: ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
        printf("\nThe Process no p%d\n",(i+1));
        printf("Enter the arrival time = ");
        scanf("%d",&at[i]);
        printf("Enter the burst time = ");
        scanf("%d",&bt[i]);
        sum_bt+=bt[i];
  }
  bt[9]=9999;
  printf("\nProcess || Arrival Time || Burst Time || Waiting_Time || Turn_Around \n");
  for(time=0;time<sum_bt;)
  {
    smallest=9;
    for(i=0;i<n;i++)
    {
      if(at[i]<=time && bt[i]>0 && bt[i]<bt[smallest])
        smallest=i;
    }
    tat=time+bt[smallest]-at[smallest];
    wt=time-at[smallest];
    printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\n",smallest+1,at[smallest],bt[smallest],wt,tat);
    sumt+=tat;
    sumw+=wt;
    time+=bt[smallest];
    bt[smallest]=0;
  }
  printf("\n\naverage waiting time = %f",sumw*1.0/n);
  printf("\naverage turnaround time = %f",sumt*1.0/n);
  return 0;
}
