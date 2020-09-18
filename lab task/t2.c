#include<stdio.h>
struct roundrobin{
    int at;
    int bt;
    int rt;
    int pno;
}process[10];
void main()
{
    int count=0,remain=0,time=0,i,j,turn_around=0,waiting_time=0,sum1=0,sum2=0;
    int qno,no,x=0;
    printf("Enter the number of process = ");
    scanf("%d",&no);
    printf("Enter the Quantum no = ");
    scanf("%d",&qno);
    remain=no;
    for(i=0;i<no;i++)
    {
        printf("\nThe Process no p%d\n",(i+1));
        printf("Enter the arrival time = ");
        scanf("%d",&process[i].at);
        printf("Enter the burst time = ");
        scanf("%d",&process[i].bt);
        process[i].rt=process[i].bt;
        process[i].pno=i+1;
    }
    for(i=0;i<no;i++)
    {
        for(j=0;j<no;j++)
        {
            if(process[i].at==process[j].at)
                continue;
            if(process[i].at<process[j].at)
            {
                int temp;
                temp=process[j].at;
                process[j].at=process[i].at;
                process[i].at=temp;

                temp=process[j].bt;
                process[j].bt=process[i].bt;
                process[i].bt=temp;

                temp=process[j].rt;
                process[j].rt=process[i].rt;
                process[i].rt=temp;

                temp=process[j].pno;
                process[j].pno=process[i].pno;
                process[i].pno=temp;

            }
        }
    }
    /*printf("P\tat\tbt\n");
    for(i=0;i<no;i++)
    {
        printf("p%d\t%d\t%d\n",(i+1),process[i].at,process[i].bt);

    }*/
    printf("\nProcess || Arrival Time || Burst Time || Waiting_Time || Turn_Around \n");
    while(remain!=0)
    {
        if(process[count].rt<=qno&&process[count].rt>0)
        {
            time+=process[count].rt;
            process[count].rt=0;
            x=1;
        }
        else if(process[count].rt>0)
        {
            time+=qno;
            process[count].rt-=qno;
        }
        if(process[count].rt==0&&x==1)
        {
                turn_around=time-process[count].at;
                waiting_time=time-process[count].at-process[count].bt;
                sum2+=waiting_time;
                sum1+=turn_around;
                printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\n",process[count].pno,process[count].at,process[count].bt,waiting_time,turn_around);
                remain--;
        }
        if(count==no-1)
            count=0;
        else if(process[count+1].at<=time)
            count++;
        else
            count=0;
    }

    printf("Average Turn_Around Time = %.2f\n",(sum1*1.0/no));
    printf("Average Waiting Time = %.2f\n",(sum2*1.0/no));
}
