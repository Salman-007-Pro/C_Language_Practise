#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<dos.h>
//Arrow move keys//
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
//**************//
//Global variable//
int l=0;
int len=0,score=0;;
char key,ch;
int life=3;
int count=0;
char sign='>';
//**************//
//Functions//
void load();
void Print();
void delay();
void move();
void Food();
void gotoxy(int x,int y);
void Bend();
void border();
void up();
void down();
void right();
void left();
void ExitGame();
void Score();
void Gameover();
void quit();
void checkbody();
//********//
//Structure//
struct coordinate{
    int x;
    int y;
    int direction;
}head,tail[500],food,pre,pre2;
//*********//
// Main start here//
void main()
{
    ch='0';
    count=0;
    system("cls");
    fflush(stdin);
    fflush(stdout);
    Print();
    //Food();
    border();
    //length=5;
    head.x=25;
    head.y=20;
    head.direction=RIGHT;
    //Food();
    //bend[0]=head;
    //getch();
    move();
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
void Print()
{
    gotoxy(40,3);
    system("COLOR 4");
    printf("Welcome to Snake Game");
    gotoxy(40,4);
    printf("Loading!!..");
    load();
    system("cls");
    fflush(stdout);
    gotoxy(35,3);
    printf("##### #     # ##### #  # #####\n");
    gotoxy(35,4);
    printf("#     ##    # #   # # #  #\n");
    gotoxy(35,5);
    printf("#     # #   # #   # ##   #\n");
    gotoxy(35,6);
    printf("##### #  #  # ##### ##   #####\n");
    gotoxy(35,7);
    printf("    # #   # # #   # # #  #\n");
    gotoxy(35,8);
    printf("    # #    ## #   # #  # #\n");
    gotoxy(35,9);
    printf("##### #     # #   # #  # #####\n");
    gotoxy(35,10);
    printf("\t <----The GAME---->\n");
    gotoxy(35,11);
    printf("Instruction:Arrow Key");
    gotoxy(35,12);
    printf("Press 1 for Start\n");
    gotoxy(35,13);
    printf("Press 2 for exit\n");
    //fflush(stdin);
    ch=getch();
    switch(ch)
    {
        case '2':
            exit(0);
        break;
        case '1':
            system("cls");
            gotoxy(40,4);
            printf("loading...");
            load();
        break;
    }
   /* if(ch=='2')
    {
        exit(0);
    }
    if(ch=='1')
    {
        system("cls");
        gotoxy(40,4);
        printf("loading...");
        load();
    }*/

}
void load()
{
    char ce=178,ch=177,i;
    gotoxy(37,6);
    for(i=0;i<=26;i++)
    {
        printf("%c",ch);
    }
    gotoxy(37,6);
    for(i=0;i<=26;i++)
    {
        delay();
        printf("%c",ce);
    }
}
void delay()
{
 for (int c = 1; c <= 32767; c++)
       for (int d = 1; d <= 2000; d++);
}
void border()
{
    int j,i=0,z;
    system("cls");
    fflush(stdin);
    fflush(stdout);
    gotoxy(food.x,food.y);
    printf("F");
    gotoxy(head.x,head.y);
    printf("%c",sign);
    for(z=1;z<=count;z++)
    {
        gotoxy(tail[z].x,tail[z].y);
        printf("o");
    }
    gotoxy(8,8);
    printf("Score = %d\n",score);
    gotoxy(9,9);
    //fflush(stdout);
    printf("Life = %d",life);
    //fflush(stdout);
    for(j=10;j<71;j++)
        {
            gotoxy(j,10);
            printf("#");
            gotoxy(j,30);
            printf("#");
        }
    for(j=10;j<=30;j++)
        {
            gotoxy(10,j);
            printf("#");
            gotoxy(70,j);
            printf("#");
        }
}
void Food()
{
    if(head.x==food.x&&head.y==food.y)
    {
        count++;
        Score();
        time_t a;
        a=time(NULL);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x=food.x+11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y=food.y+11;
    }
    else if(food.x==0||food.y==0)
    {
        time_t a;
        a=time(NULL);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x=food.x+11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y=food.y+11;
    }
}
void Delay()
{
    long double i;
    for(i=0;i<=(10000000);i++);
}
void move()
{
    int a,i;
    do
    {
        fflush(stdout);
        Food();
        Bend();
        checkbody();
        Delay();
        //delay();
        border();
        if(head.direction==RIGHT)
            right();
        else if(head.direction==LEFT)
            left();
        else if(head.direction==UP)
            up();
        else
            down();

    }while(!kbhit());
    a=getch();
    if(a==27)
        quit();
    key=getch();
    if(key==77&&head.direction!=RIGHT&&head.direction!=LEFT)
    {
        //right
        //head.direction=key;
        head.direction=77;
        sign='>';
        move();
    }
    else if(key==72&&head.direction!=UP&&head.direction!=DOWN)
    {
        //up
        //head.direction=key;
        head.direction=72;
        sign='^';
        move();
    }
    else if(key==80&&head.direction!=UP&&head.direction!=DOWN)
    {
        //down
        //head.direction=key;
        head.direction=80;
        sign='v';
        move();
    }
    else if(key==75&&head.direction!=RIGHT&&head.direction!=LEFT)
    {
        //left
        //head.direction=key;
        head.direction=75;
        sign='<';
        move();
    }
    else if(key==27)
    {
        quit();
    }
    else{
        //printf("\a");
        move();
    }
}
void right()
{
    head.x++;
    Gameover();
}
void up()
{
    head.y--;
    Gameover();
}
void down()
{
    head.y++;
    Gameover();
}
void left()
{
    head.x--;
    Gameover();
}
void Bend()
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
}
void Gameover()
{
    /*if(((head.x==70||head.x==10||head.y==30||head.y==10)&&len==0)||l==1)
    {
        //getch();
        life--;
         if(life==0)
        {
            len=1;
        }
        head.x=25;
        head.y=20;
        head.direction=RIGHT;
        count=0;
        l=0;
        sign='>';
        move();
    }
    if((head.x==70||head.x==10||head.y==30||head.y==10)&&life==0)
    {
        getch();
        fflush(stdin);
        system("cls");
        fflush(stdout);
        count=0;
        life=3;
        score=0;
        sign='>';
        ch='0';
        delay();
        delay();
        delay();
        fflush(stdin);
        gotoxy(40,5);
        printf("Game is over and Score: %d\n",score);
        load();
        main();
    }*/
    if(l==1)
    {
        //getch();
        if(life>0)
        {
            life--;
            head.x=25;
            head.y=20;
            head.direction=RIGHT;
            count=0;
            l=0;
            sign='>';
            if(life==0)
                goto l1;
            move();
        }
        if(life==0)
            goto l1;
    }
    if(head.x==70||head.x==10||head.y==30||head.y==10)
    {
        if(life>0)
        {
            life--;
            head.x=25;
            head.y=20;
            head.direction=RIGHT;
            count=0;
            l=0;
            sign='>';
            if(life==0)
                goto l1;
            move();
        }
        if(life==0)
        {
            l1:
            getch();
            fflush(stdin);
            system("cls");
            fflush(stdout);
            count=0;
            life=3;
            sign='>';
            ch='0';
            delay();
            delay();
            delay();
            fflush(stdin);
            gotoxy(40,5);
            printf("Game is over and Score: %d\n",score);
            score=0;
            load();
            main();
        }
    }
}
void quit()
{
    system("cls");
    printf("The Score = %d\n",score);
    printf("You Quit the game");
    getche();
}
void Score()
{
    score=score+10;
}
void checkbody()
{
    int i;
    for(i=1;i<=count;i++)
    {
        if((head.x==tail[i].x)&&(head.y==tail[i].y))
        {
            getch();
            Gameover();
            l=1;
        }

    }
}
