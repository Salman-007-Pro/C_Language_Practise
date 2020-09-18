#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    int a=6,*p,**q,***r;
    p=&a;
    q=&p;
    r=&q;
    printf("a = %d\n",a);
    printf("p = %u\n",p);
    printf("q = %u\n",**q);
    printf("r = %u\n",***r);
}
