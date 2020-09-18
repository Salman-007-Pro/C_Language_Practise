#include<stdio.h>
#include<conio.h>
struct firstcome{
    int at;
    int bt;
    int rt;
    int p;
}process[10];
void main()
{
    int count=0,time=0,waitingtime=0,turn_around=0,flag=0,no,remain,i,j=0,k=1,max_at,max[10],x=0,sum1=0,sum2=0;
    printf("Enter the no of process = ");
    scanf("%d",&no);
    remain=no;
    for(i=0;i<no;i++)
    {
        printf("\nProcess no p%d\n",(i+1));
        printf("Enter the arrival time = ");
        scanf("%d",&process[i].at);
        fflush(stdin);
        printf("Enter the burst time = ");
        scanf("%d",&process[i].bt);
        process[i].rt=process[i].bt;
        max[i]=process[i].at;
    }
    max_at=process[0].at;
    for(i=0;i<no;i++)
    {
        if(max_at<process[i].at)
            max_at=process[i].at;
    }
    j=0;
    while(j!=max_at+1)
    {
        for(i=0;i<no;i++)
        {
            if(process[i].p>0)
                continue;
            if(process[i].at==j)
            {
            process[i].p=k;
            k++;
            }
        }
        j++;
    }
    j=0;
    x=1;
    //printf("Ready queue\n");
    //for(i=0;i<no;i++)
    printf("\nProcess || Arrival Time || Burst Time || Waiting_Time || Turn_Around \n");
    while(remain!=0)
    {
        for(j=0;j<no;j++)
        {
            if(process[j].p==x)
            {
                time+=process[j].bt;
                turn_around=time-process[j].at;
                waitingtime=time-process[j].at-process[j].bt;
                sum2+=waitingtime;
                sum1+=turn_around;
                printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\n",(j+1),process[j].at,process[j].bt,waitingtime,turn_around);
                remain--;
            }
        }
        x++;
    }
    printf("Average Turn_Around Time = %.2f\n",(sum1*1.0/no));
    printf("Average Waiting Time = %.2f\n",(sum2*1.0/no));
}
