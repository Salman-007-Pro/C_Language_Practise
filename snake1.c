#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
struct snakebody
{
    int x;
    int y;
}head,tail[100],pre,pre2,food;
int count=0;
int score=0,flag=0;
int gameover=0;
char key;
char sign='>';
time_t a;
void gotoxy(int x,int y);
void map();
void move();
void update();
void delay();
void Gameover();
void main()
{
    head.x=70/2;
    head.y=30/2;
    a=time(NULL);
    srand(a);
    food.x=rand()%70;
    food.y=rand()%30;
    if(food.x==0)
        food.x++;
    if(food.y==0)
        food.y++;
    while(!gameover)
    {
        map();
        //delay();
        update();
        move();
        //getch();
        //update();
    }
    Gameover();
}
void gotoxy(int x,int y)
{
    COORD c;
    HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);
    fflush(stdout);
    c.X=x;
    c.Y=y;
    fflush(stdout);
    SetConsoleCursorPosition(a,c);
}
void map()
{
    int z=0;
    delay();
    system("cls");
    int i;
    for(i=0;i<=70;i++)
    {
        gotoxy(i,0);
        printf("#");
        gotoxy(i,30);
        printf("#");
    }
    gotoxy(head.x,head.y);
    printf("%c",sign);
    //printf("O");
    for(i=0;i<=30;i++)
    {
        gotoxy(0,i);
        printf("#");
        gotoxy(70,i);
        printf("#");
    }
    for(i=0;i<count;i++)
    {
        gotoxy(tail[i].x,tail[i].y);
        printf("o");
    }
    if(head.x==food.x&&head.y==food.y)
    {
        count++;
        score=score+10;
        srand(a);
        food.x=rand()%70;
        food.y=rand()%30;
        if(food.x==0)
        food.x++;
        if(food.y==0)
        food.y++;
        gotoxy(food.x,food.y);
        printf("f");
        z=1;

    }
    if(!z)
    {
        fflush(stdout);
        gotoxy(food.x,food.y);
        printf("f");
        fflush(stdout);
    }
    if(head.x==0||head.x==70||head.y==0||head.y==30)
        gameover=1;
}
void update()
{
    //delay();
    if(kbhit())
    {

        switch(key=getch())
        {
            case UP:
                flag=1;
            break;
            case DOWN:
                flag=2;
            break;
            case LEFT:
                flag=3;
            break;
            case RIGHT:
                flag=4;
            break;
        }
    }
}
void move()
{
    int i;
    pre.x=tail[0].x;
    pre.y=tail[0].y;
    tail[0].x=head.x;
    tail[0].y=head.y;
    for(i=1;i<=count;i++)
    {
        pre2.x=tail[i].x;
        pre2.y=tail[i].y;
        tail[i].x=pre.x;
        tail[i].y=pre.y;
        pre.x=pre2.x;
        pre.y=pre2.y;

    }
    switch(flag)
    {
        case 1:
            head.y--;
            sign='^';
        break;
        case 2:
            head.y++;
            sign='v';
        break;
        case 3:
            head.x--;
            sign='<';
        break;
        case 4:
            head.x++;
            sign='>';
        break;
    }

}
void delay()
{
 for (int c = 1; c <= 32767; c++)
       for (int d = 1; d <= 2000; d++);
}
void Gameover()
{
    system("cls");
    printf("The Score is %d",score);
    getche();
}
