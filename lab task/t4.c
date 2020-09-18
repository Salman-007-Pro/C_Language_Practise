#include<stdio.h>
#include<conio.h>
////Implementation of Priority
void main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    printf("Enter Total Number of Process: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nThe Process no p%d\n",(i+1));
        printf("Enter the burst time = ");
        scanf("%d",&bt[i]);
        printf("Enter the priority = ");
        scanf("%d",&pr[i]);
        p[i]=i+1;
    }
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;    //waiting time for first process is zero

    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    avg_wt=total/n;      //average waiting time
    total=0;
    printf("\nProcess || Burst Time || Priority || Waiting_Time || Turn_Around \n");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],pr[i],wt[i],tat[i]);
    }

    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time: %d",avg_wt);
    printf("\nAverage Turnaround Time: %d\n",avg_tat);

}

