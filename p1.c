#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    int sum=0,*ptr,*p,i,n;
    printf("Enter the number store in array = ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    if(ptr==NULL)
        exit(0);
    p=ptr;
    printf("Enter the element\n");
    for(i=1;i<=5;i++)
    {
        scanf("%d",ptr);
        sum=sum+*ptr;
        ptr++;
    }
    printf("\nShow the element\n");
    for(i=1;i<=5;i++)
    {
        printf("%d\n",*p++);
    }
    printf("\nThe sum is %d",sum);

}
