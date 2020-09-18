#include<stdio.h>
#include<conio.h>
#include<windows.h>
typedef struct coordinate
{
    int x,y,direction;
}ab;
void main()
{
    ab food;
    system("cls");
    int i;
    gotoxy(food.x,food.y);
        printf("f");
        for(i=10;i<71;i++)
        {
            gotoxy(i,10);
            printf("#");
            gotoxy(i,30);
            printf("#");
        }
        for(i=10;i<31;i++)
        {
            gotoxy(10,i);
            printf("#");
            gotoxy(70,i);
            printf("#");
        }

}
void gotoxy(int x,int y)
{
    COORD c;
    HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);
    fflush(stdout);
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(a,c);
}
