#include<stdio.h>
#include<conio.h>
struct sjfnon{
    int bt;
    int at;
    int rt;
    int p;
    int pno;
}process[10];
void main()
{
    int time=0,remain=0,time_around=0,waiting_time=0,i,j,sum1=0,sum2=0;
    int no,x=1,flag=0;
    printf("Enter the number of process = ");
    scanf("%d",&no);
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
            /*if(process[i].bt<process[j].bt)
            {

            }*/


        }
    }
     printf("P\tat\tbt\n");
    for(i=0;i<no;i++)
    {
        printf("p%d\t%d\t%d\n",process[i].pno,process[i].at,process[i].bt);

    }
    /*for(i=0;i<no;i++)
    {
        for(j=0;j<no;j++)
        {
            if(process[i].bt<process[j].bt)
            {
                process[i].p=x;
            }
        }
        x++;
    }*/
    int max_bt=process[0].bt;
    for(i=0;i<no;i++)
    {
        if(max_bt<process[i].bt)
            max_bt=process[i].bt;
    }
    j=0;
    while(j!=max_bt+1)
    {
        for(i=0;i<no;i++)
        {
            if(process[i].p>0)
                continue;
            if(process[i].bt==j)
            {
            process[i].p=k;
            k++;
            }
        }
        j++;
    }
    x=1;
    int v=1,f=0;
    printf("\nProcess || Arrival Time || Burst Time || Waiting_Time || Turn_Around \n");
    while(remain!=0)
    {
        if(process[count].rt>0&&process[count].p==x)
        {
            time+=process[count].rt;
            process[count].rt=0;
            flag=1;
            x++;

        }
        if(flag==1)
        {
                turn_around=time-process[count].at;
                waiting_time=time-process[count].at-process[count].bt;
                sum2+=waiting_time;
                sum1+=turn_around;
                printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\n",process[count].pno,process[count].at,process[count].bt,waiting_time,turn_around);
                remain--;
                flag=0;
        }
        if(process[count].rt>0)
        {
            time+=1;
            process[count].rt-=1;
        }
        v++;
        if(v>1)
        {

            for(i=0;i<v;i++)
            {
                for(j=0;j<v;j++)
                {
                    if(process[i].bt<process[j].bt)
                        count=i;
                    else
                        count=j;

                }
            }
        }
        if(count==no-1)
            count=0;


    }

}
