#include<Stdio.h>
#include<conio.h>
void main()
{
    int m,*ab;
    ab=&m;
    *ab=29;
    printf("Address of m: %u\n",&m);
    printf("value of m: %d\n",m);
    printf("Address of pointer ab: %u\n",ab);
    printf("Content of pointer ab: %d\n",*ab);
    *ab=34;
    printf("Address of pointer ab: %u\n",ab);
    printf("Content of pointer ab: %d\n",*ab);
    *ab=7;
    printf("Address of m: %u\n",&m);
    printf("value of m: %d\n",m);
}
