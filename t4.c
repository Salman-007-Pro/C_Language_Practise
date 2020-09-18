#include<stdio.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x,int y);
void main()
{
    printf("********************\n*\n*\n*\n*\n*");
    gotoxy(20,5);
    printf("My name is muhammad Salman Asif");
    //fflush(stdout);
    printf("asdas");


}
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,c);
}
