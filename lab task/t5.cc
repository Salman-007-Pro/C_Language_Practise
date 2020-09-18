//Implementation of Priority(Preemptive)
#include<stdio.h>
#include<conio.h>
#include<algorithm>
using namespace std;
typedef struct proccess
{
	int at,bt,ct,ta,wt,p_id,pr,tbt;
	//int bbt;
	//string pro_id;
	/*
	artime = Arrival time,
	bt = Burst time,
	ct = Completion time,
	ta = Turn around time,
	wt = Waiting time
	*/

}schedule;

bool compare(schedule a,schedule b)
{
	return a.at<b.at;
	/* This schedule will always return TRUE
	if above condition comes*/
}

bool compare2(schedule a,schedule b)
{
	return a.pr>b.pr;
	/* This schedule will always return TRUE
	if above condition comes*/
}

int main()
{
	schedule pro[10];
	int n,i,j,pcom,sum1=0,sum2=0;

	printf("Enter the number of process: ");
	scanf("%d",&n);
	/*for(i=0;i<n;i++)
	{
		cin>>pro[i].pro_id;
		cin>>pro[i].at;
		cin>>pro[i].bt;
		pro[i].btt=pro[i].bt;
		cin>>pro[i].pr;
	}*/
    for(i=0;i<n;i++)
    {
        pro[i].p_id=i+1;
        printf("\nThe Process no p%d\n",(i+1));
        printf("Enter the arrival time = ");
        scanf("%d",&pro[i].at);
        printf("Enter the burst time = ");
        scanf("%d",&pro[i].bt);
        pro[i].tbt=pro[i].bt;
        printf("Enter the priority = ");
        scanf("%d",&pro[i].pr);
    }

	sort(pro,pro+n,compare);
	/*sort is a predefined funcion  defined in
	algorithm.h header file, it will sort the
	schedulees according to their arrival time*/

	i=0;
	pcom=0;
	while(pcom<n)
	{
		for(j=0;j<n;j++)
		{
			if(pro[j].at>i)
			break;
		}
		sort(pro,pro+j,compare2);
		if(j>0)
		{
			for(j=0;j<n;j++)
			{
				if(pro[j].bt!=0)
				break;
			}
			if(pro[j].at>i)
			i+=pro[j].at-i;
			pro[j].ct=i+1;
			pro[j].bt--;
		}

		i++;
		pcom=0;
		for(j=0;j<n;j++)
		{
			if(pro[j].bt==0)
			pcom++;
		}
	}
    printf("\nProcess || Arrival Time || Burst Time || Priority || Completion Time || Waiting_Time || Turn_Around \n");
	for(i=0;i<n;i++)
	{
		pro[i].ta=pro[i].ct-pro[i].at;
		sum1=sum1+pro[i].ta;
		pro[i].wt=pro[i].ta-pro[i].tbt;
		sum2=sum2+pro[i].wt;
		//before executing make it in one statement
		printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pro[i].p_id,pro[i].at,pro[i].tbt,pro[i].pr,pro[i].ct,pro[i].wt,pro[i].ta);
	}
    printf("\n\nAverage Waiting Time: %.2f",(sum2*1.0/n));
    printf("\nAverage Turnaround Time: %.2f\n",(sum1*1.0/n));
    return 0;

}
