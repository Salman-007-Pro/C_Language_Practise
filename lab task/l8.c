#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int sum;
void *runner(void *param);
void main(int argc,char *argv[])
{
    pthread_t tid;
    pthread_attr_t attr;
    if(argc!=2)
    {
        printf("Usage: a.out<integer value>\n");
        exit(0);
    }
    if(atoi(argv[1])>0)
    {
        printf("%d must be >=0\n",atoi(argv[1]));
        exit(0);
    }
    pthread_attr_init(&attr);
    pthread_create(&tid,&attr,runner,argv[1]);
    pthread_join(tid,NULL);
    printf("Sum = %d\n",sum);
}
void *runner(void *param)
{

    int upper=atoi(param);
    int i;
    sum=0;
    if(upper>0)
    {
        for(i=1;i<upper;i++)
        {
            sum++;
        }
        pthread_exit(0);
    }
}
