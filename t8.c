#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    time_t a;
    a=time(NULL);
    printf("a=%d",a);
    int b;
    srand(a);
    b=rand()%10;
    printf("\n%d",b);
}
