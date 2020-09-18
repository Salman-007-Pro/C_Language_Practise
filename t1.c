#include<stdio.h>
#include<conio.h>
struct student{
    int roll;
    char name[10];
};
typedef struct student students;
students stu1[10];
void main()
{
    int i;
    for(i=0;i<2;i++)
    {
        printf("\nThe student no %d\n",(i+1));
        printf("enter the name = ");
        scanf("%s",&stu1[i].name);
        printf("enter the roll = ");
        scanf("%d",&stu1[i].roll);
    }
    for(i=0;i<2;i++)
    {
        printf("\nData of student no %d\n",(i+1));
        printf("Name: %s\n",stu1[i].name);
        printf("Roll: %d\n",stu1[i].roll);
    }
    getche();
}
