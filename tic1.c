#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
// normal game function
int gameover=0,sel=4,k,n=0,u=0,c=0,d=0;
char ch,sign1,sign2,choice1,choice2;
char board[9]={'1','2','3','4','5','6','7','8','9'};
void map();
void player1();
void player2();
void ai();
int Win(char a);
int draw(char a , char b);
int checkgame(char a,char b);
void loading();
void designmain();
void gotoxy(int x,int y);
void delay();
void choice();
void random();
void symbol();
void playagain();
void score();
char convert(int a);
// AI Coding
typedef struct move{
    int sele;
}moves;
char player,opponent;
int maxi(int a,int b);
int mini(int a,int b);
int isMovesleft(char board[]);
int evaluate(char b[]);
int minimax(char board[],int depth,int isMax);
moves findbestmove(char board[]);

//move check condition
int maxi(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int mini(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
int isMovesleft(char board[])
{
    int i;
    for(i=0;i<9;i++)
    {
        if('1'<=board[i]&&board[i]<='9')
            return 1; //true
    }
    return 0; //false
}
int evaluate(char b[])
{
    int i,j;
    for(i=0;i<9;i+=3)
    {
        if(b[i]==b[i+1]&&b[i]==b[i+2])
        {
            if(b[i]==player)
                return +10;
            else if(b[i]==opponent)
                return -10;
        }
        //printf("\ni=%d\n",i);
    }
    for(i=0;i<4;i++)
    {
        if(b[i]==b[i+3]&&b[i]==b[i+6])
        {
            if(b[i]==player)
                return +10;
            else if(b[i]==opponent)
                return -10;
        }
       // printf("i=%d\n",i);
    }
    if(b[0]==b[4]&&b[0]==b[8])
    {
        if(b[0]==player)
            return +10;
        else if(b[0]==opponent)
            return -10;
    }
    if(b[2]==b[4]&&b[2]==b[6])
    {
        if(b[2]==player)
            return +10;
        else if(b[2]==opponent)
            return -10;
    }
    return 0;
}
int minimax(char board[],int depth,int isMax)
{
    int score=evaluate(board);
    //maximizer won the game
    if(score==10)
        return score;
    //minimizer won the game
    if(score==-10)
        return score;
    //check board how many are remaining
    if(isMovesleft(board)==0)
        return 0;

    if(isMax)//player maximizer
    {
        int best=-1000;
        int value;
        int i;
        char c;
        for(i=0;i<9;i++)
        {
            if('1'<=board[i]&&board[i]<='9')
            {
                c=board[i];
                board[i]=player;

                //Call minimax recursively
                value= minimax(board, depth+1, !isMax);
                best=maxi(value,best);

                //undo the turn
                board[i]=c;
            }
        }
        return best;
    }
    else // opponent minimizer
    {
        int best = 1000;
        int value;
        int i;
        char c;
        for(i=0;i<9;i++)
        {
            if('1'<=board[i]&&board[i]<='9')
            {
                c=board[i];
                board[i]=opponent;

                //Call minimax recursively
                 value= minimax(board, depth+1, !isMax);
                 best=mini(value,best);

                //undo the turn
                board[i]=c;
            }
        }
        return best;
    }
}
moves findbestmove(char board[])
{
    int bestvalue=-1000;
    moves bestMove;
    bestMove.sele=-1;
    int i;
    char c;
    for(i=0;i<9;i++)
        {
            if('1'<=board[i]&&board[i]<='9')
            {
                c=board[i];
                board[i]=player;

                //Call minimax recursively
                 int moveVal= minimax(board,0,0);

                //undo the turn
                board[i]=c;
                if(moveVal>bestvalue)
                {
                    bestMove.sele=i;
                    bestvalue=moveVal;
                }
            }
        }
    //printf("The value of the best Move is : %d\n",bestvalue);
    return bestMove;
}

//Normal Game
void main()
{
    random();
    //3loading();
    designmain();
    //map();
    getch();
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
void loading()
{
    system("cls");
    char ce=178,ch=177;
    int i=0,a=0;
    gotoxy(37,5);
    printf("Loading!..");
    gotoxy(37,6);
    for(i=0;i<=26;i++)
    {
        printf("%c",ch);
    }
    for(i=0;i<=26;i++)
    {
        delay();
        gotoxy(37+i,6);
        printf("%c",ce);

    }

}
void delay()
{
    int i,j,a=0;
    for(i=0;i<=10000;i++)
    {
        for(j=0;j<=10000;j++);

    }
}
void designmain()
{
    int a=0;
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t\t\tTTTTT IIIII CCCC  TTTTT AAAA CCCC  TTTTT OOOO EEEE \n");
    printf("\t\t\t\t  T     I   C       T   A  A C       T   O  O E    \n");
    printf("\t\t\t\t  T     I   C       T   AAAA C       T   O  O EEE  \n");
    printf("\t\t\t\t  T     I   C       T   A  A C       T   O  O E    \n");
    printf("\t\t\t\t  T   IIIII CCCC    T   A  A CCCC    T   OOOO EEEE \n");
    printf("\t\t\t\t================================================== \n");
    printf("\n\t\t\t\t\t\t      ::START::\n");
    printf("\n\t\t\t\t\t1: Play player:1 with player:2");
    printf("\n\t\t\t\t\t2: Play player:1 with computer");
    printf("\n\t\t\t\t\t3: Exit\n");
    switch(ch=getch())
    {
        case '1':
            if(sel!=1)
            {
                d=0;
                u=0;
                c=0;
            }
            sel=1;
            loading();
            choice();
            map();
        break;

        case '2':
             if(sel!=2)
            {
                d=0;
                u=0;
                c=0;
            }
            sel=2;
            loading();
            choice();
            map();
        break;

        case '3':
            exit(0);
        break;

        default:
            designmain();
            fflush(stdin);

    }
}
void choice()
{
    int a=0;
    system("cls");
    printf("Plz select symbol only(X,O)\n");
    if(ch=='1')
    {
        do
        {
            if(a>0)
            {
                system("cls");
                printf("Plz select symbol only(X,O)\n");
                fflush(stdin);
            }
            printf("Enter the symbol of player.1: ");
            scanf("%c",&sign1);
            a=1;
        }while(sign1!='O'&&sign1!='o'&&sign1!='X'&&sign1!='x');

        if(sign1=='O')
            sign2='X';

        if(sign1=='o')
            sign2='x';

        if(sign1=='X')
            sign2='O';

        if(sign1=='x')
            sign2='o';
    }
    a=0;
    if(ch=='2')
    {
         do
        {
            if(a>0)
            {
                system("cls");
                printf("Plz select symbol only(X,O)\n");
                fflush(stdin);
            }
            printf("Enter the symbol of player.1: ");
            scanf("%c",&sign1);
            a=1;
        }while(sign1!='O'&&sign1!='o'&&sign1!='X'&&sign1!='x');
        opponent=sign1;
        if(sign1=='O')
            sign2='X';

        if(sign1=='o')
            sign2='x';

        if(sign1=='X')
            sign2='O';

        if(sign1=='x')
            sign2='o';
        player=sign2;
    }
}
void map()
{
    int l,m,n=0;
    system("cls");
    symbol();
    printf("\n\n\n\n\n");
    printf("\t\t\t      <---The BOARD--->\n");
    printf("\t\t\t      =================\n\n");
    printf("\t\t\t\t  %c | %c  | %c \n",board[0],board[1],board[2]);
    printf("\t\t\t\t____|____|____\n");
    printf("\t\t\t\t  %c | %c  | %c \n",board[3],board[4],board[5]);
    printf("\t\t\t\t____|____|____\n");
    printf("\t\t\t\t  %c | %c  | %c \n",board[6],board[7],board[8]);
    printf("\t\t\t\t    |    |    \n");
    printf("\n\n");
    score();
    if(sel==2&&k==1)
    {
        printf("Player: AI \n");
    }
    else
        printf("Player: %d \n",k+1);
    fflush(stdin);
    if(k==0&&sel==1)
    {
        player1();
        map();
    }
    if(k==1&&sel==1)
    {
        player2();
        map();
    }
    if(k==0&&sel==2)
    {
        player1();
        map();
    }
    if(k==1&&sel==2)
    {
        ai();
        map();
    }
}
void player1()
{
    int x=0,s=0,h=0;
    fflush(stdin);
    do
    {
        fflush(stdin);
        if(n>0)
        {
           printf("wrong input\n");
        }
        printf("Enter your choice: ");
        scanf("%c",&choice1);
        n=1;
        x=checkgame(choice1,sign1);
        s=Win(sign1);
        fflush(stdin);
    }while(!('1'<=choice1&&choice1<='9')||x!=1);
    n=0;
    h=draw(sign1,sign2);
    if(h==1)
    {
        printf("Draw the game");
        getch();
        playagain();
    }
    if(s==1)
        {
            printf("The winner is player No 1");
            getch();
            playagain();
        }
    k=1;
}
void player2()
{
    int x=0,s=0,h=0;
    fflush(stdin);
    do
    {
        fflush(stdin);
        if(n>0)
        {
            printf("Something wrong\n");
        }
        printf("Enter your choice: ");
        scanf("%c",&choice2);
        n=1;
        x=checkgame(choice2,sign2);
        s=Win(sign2);
        fflush(stdin);
    }while(!('1'<=choice2&&choice2<='9')||x!=1);
    n=0;
    h=draw(sign1,sign2);
    if(h==1)
    {
        printf("Draw the game");
        getch();
        playagain();
    }
     if(s==1)
        {
            printf("The winner is player No 2");
            getch();
            playagain();
        }
    k=0;
}
void ai()
{
    int x=0,s=0,h=0;
    fflush(stdin);
    moves bestmove=findbestmove(board);
    bestmove.sele=bestmove.sele+1;
    printf("Selection value is %d\n",bestmove.sele);
    getche();
    char z;
    z=convert(bestmove.sele);
    x=checkgame(z,sign2);
    s=Win(sign2);
    fflush(stdin);
    n=0;
    h=draw(sign1,sign2);
    if(h==1)
    {
        printf("Draw the game");
        getch();
        playagain();
    }
     if(s==1)
        {
            printf("The winner is AI");
            getch();
            playagain();
        }
    k=0;
}
char convert(int a)
{
    if(a==1)
        return '1';
    else if(a==2)
        return '2';
    else if(a==3)
        return '3';
    else if(a==4)
        return '4';
    else if(a==5)
        return '5';
    else if(a==6)
        return '6';
    else if(a==7)
        return '7';
    else if(a==8)
        return '8';
    else
        return '9';

}
int checkgame(char a,char b)
{
    int i,v;
    for(i=0;i<9;i++)
    {
        if(a==board[i])
        {
            board[i]=b;
            v=1;
            break;
        }
        v=0;
    }
    return v;
}
int Win(char a)
{
    if(a==board[0]&&a==board[1]&&a==board[2])
    {
        if(a==sign1)
            u++;
        else
        c++;
        return 1;
    }
    else if(a==board[3]&&a==board[4]&&a==board[5])
    {
        if(a==sign1)
            u++;
        else
        c++;
        return 1;
    }
    else if(a==board[6]&&a==board[7]&&a==board[8])
    {
        if(a==sign1)
            u++;
        else
        c++;
        return 1;
    }
    else if(a==board[0]&&a==board[3]&&a==board[6])
    {
        if(a==sign1)
            u++;
        else
        c++;
        return 1;
    }
    else if(a==board[1]&&a==board[4]&&a==board[7])
    {
        if(a==sign1)
            u++;
        else
        c++;
        return 1;
    }
    else if(a==board[2]&&a==board[5]&&a==board[8])
    {
        if(a==sign1)
            u++;
        else
        c++;
        return 1;
    }
    else if(a==board[0]&&a==board[4]&&a==board[8])
    {
        if(a==sign1)
            u++;
        else
        c++;
        return 1;
    }
    else if(a==board[2]&&a==board[4]&&a==board[6])
    {
        if(a==sign1)
            u++;
        else
        c++;
        return 1;
    }
    else
        return 0;

}
int draw(char a,char b)
{
    int count=0,i;
    for(i=0;i<9;i++)
    {
        if(a==board[i]||b==board[i])
            count++;
    }
    if(count==9)
    {
        d++;
        return 1;
    }
    else
        return 0;
}
void symbol()
{
    if(ch=='1')
    {
        printf("Symbol of player.1 and player.2\n");
        printf("Player.1: %c\n",sign1);
        printf("Player.2: %c\n",sign2);
    }
    if(ch=='2')
    {
        printf("Symbol of player.1 and Computer(A.I)\n");
        printf("Player.1: %c\n",sign1);
        printf("Computer(A.I): %c\n",sign2);
    }
}
void playagain()
{
    char ch;
        system("cls");
        board[0]='1';
        board[1]='2';
        board[2]='3';
        board[3]='4';
        board[4]='5';
        board[5]='6';
        board[6]='7';
        board[7]='8';
        board[8]='9';
        printf("Do you want to play again\n");
        printf("=========================\n");
        printf("press y for start the game again\n");
        printf("press n for exit the game\n");
        printf("Enter your choice = ");
        scanf("%c",&ch);
    switch(ch)
    {
        case 'y':
            loading();
            choice();
            //main();
        break;
        case 'Y':
            loading();
            choice();
            //main();
        break;

        case 'n':
            main();
            //exit(0);
        break;

        case 'N':
            main();
            //exit(0);
        break;

        default:
            playagain();
    }
}
void score()
{
    gotoxy(70,8);
    printf("<---SCORE--->\n");
    gotoxy(70,9);
    printf("=============\n");
    gotoxy(70,10);
    printf("|| Draw = %d\n",d);
    gotoxy(70,11);
    printf("|| Player no.1 = %d\n",u);
    if(sel==1)
    {
        gotoxy(70,12);
        printf("|| Player No.2 = %d\n",c);
    }
    else
    {
        gotoxy(70,12);
        printf("|| AI = %d\n",c);
    }
        fflush(stdout);
        gotoxy(0,18);
}
void random()
{
    time_t a;
    a=time(NULL);
    srand(a);
    k=rand()%2;
}
