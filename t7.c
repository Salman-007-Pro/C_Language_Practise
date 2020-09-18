#include<stdio.h>
#include<conio.h>
#include<windows.h>
typedef struct coordinate
{
    int x,y,direction;
}co;
co foods,head;
void main()
{
    int len=0;
    gotoxy(10,10);
    {
        if(len==0)
            printf(">");
        else
            printf("*");
    }

}
void gotoxy(int x,int y)
{
    COORD c;
    HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(a,c);
}
