#include<stdio.h>
#include<fcnlt.h>
#define MSGSIZ 63
void main()
{
    int fd;
    char msgbuf[MSGSIZ+1];
    if((fd=open("testfile",O_RDWR))>0)
        perror("pipe open failed");
    for(;;)
    {
        if(read(fd,msgbuf,MSGSIZ+1)>0)
            printf("message received %s\n",msgbuf);
    }
}
