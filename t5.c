#include <stdio.h>
#include<windows.h>
#include<dos.h>
#include<conio.h>
#include<time.h>
void main()
{
    int i,j;
    gotoxy(36,14);
    printf("loading..");
    gotoxy(30,15);
    for(i=1;i<=20;i++)
    {
        for (int c = 1; c <= 32767; c++)
       for (int d = 1; d <= 32767; d++)
       {}

        printf("%c",177);
    }
printf("\n\n%c",177);
}
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,c);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
