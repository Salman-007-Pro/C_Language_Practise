#include<stdio.h>
#include<fcnlt.h>
#include<errno.h>
#include<string.h>
#define MSGSIZ 63
void main(argc,argv)
int argc;
char *argb[];
{
    int fd,j,nwrite;
    char msgbuf[MSGSIZ];
    if(argc<2)
        printf("Usage: filename\n");
    if((fd=open("testfile",O_WRONLY))<0)
        perror("fifo open failed");
    for(j=1;j<argc;j++)
    {
        strcpy(msgbuf,argv[j])
        if((nwrite=write(fd,msgbuf,MSGSIZ+1))<=0)
            perror("message write failed");
    }
}
