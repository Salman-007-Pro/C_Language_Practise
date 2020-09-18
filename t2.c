#include<Stdio.h>
#include<conio.h>
struct studentmarks{
    int roll;
    int mark[5];
    char name[10];
    double per;
    int total;
};
typedef struct studentmarks st;
st stu[2];
int sum=0;
void main()
{
    int i;
    for(i=0;i<2;i++)
    {
        printf("\nThe student no %d\n",(i+1));
        printf("enter the name = ");
        scanf("%s",&stu[i].name);
        printf("enter the roll no = ");
        scanf("%d",&stu[i].roll);
        for(int j=0;j<5;j++)
        {
            printf("Enter the marks of subject no %d = ",(j+1));
            scanf("%d",&stu[i].mark[j]);
            sum=sum+stu[i].mark[j];
        }
        stu[i].total=sum;
        sum=0;
        stu[i].per=((stu[i].total/500.)*100);
    }
    for(i=0;i<2;i++)
    {
        printf("\nThe student no %d\n",(i+1));
        printf("Name: %s\n",stu[i].name);
        printf("Roll no: %d\n",stu[i].roll);
        for(int j=0;j<5;j++)
        {
            printf("Mark of subject no %d = %d\n",(j+1),stu[i].mark[j]);
        }
        printf("The total marks = %d\n",stu[i].total);
        printf("The percentage is %f\n",stu[i].per);
    }
    getche();
}
