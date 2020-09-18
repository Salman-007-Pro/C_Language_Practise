#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct move{
    int sel;
}moves;
char player='x',opponent='o';
int min(int a,int b);
int max(int a,int b);

//move check condition
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int min(int a,int b)
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
                best=max(value,best);

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
                 best=min(value,best);

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
    bestMove.sel=-1;
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
                printf("Moveval = %d\n",moveVal);
                getche();
                if(moveVal>bestvalue)
                {
                    bestMove.sel=i;
                    bestvalue=moveVal;
                }
            }
        }
    printf("The value of the best Move is : %d\n",bestvalue);
    return bestMove;
}
void main()
{                 //0   1   2   3   4   5   6   7   8
    char board[9]={'x','o','x','o','o','x','7','8','9'};
    moves bestmove=findbestmove(board);
    printf("The optmal move\n");
    printf("Selection is %d\n",bestmove.sel);
    printf("X is a Computer\n");
    printf("O is a Player\n");
    /*int s=isMovesleft(board);
    int a=120,b=20,c;
    c=min(a,b);
    printf("c=%d\n",c);
    c=max(a,b);
    printf("c=%d\n",c);
    printf("S= %d\n",s);*/
    getche();

}
