#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node{
    char board1[9];
    int w;
    struct Node *a1,*a2,*a3,*a4,*a5,*a6,*a7,*a8,*a9;
}node;
char board[9]={'o','x','o','3','x','o','6','7','8'};
char turn='c';
node* getnew(char board[])
{
    node *root=(node*)malloc(sizeof(node));

    for(int i=0;i<9;i++)
    {
      root->board1[i]=board[i];
    }
    root->a1=root->a2=root->a3=root->a4=root->a5=root->a6=root->a7=root->a8=root->a9=NULL;
    return root;
}
node* newcreat(char board[],int a,char turn)
{
    node *root=(node*)malloc(sizeof(node));
    //root->board1[9]=('0','0','0','0','0','0','0','0','0');
    for(int i=0;i<9;i++)
    {
      root->board1[i]=board[i];
    }
    root->board1[a]=turn;
    //root->w=Wins(board1[9],turn);
    root->a1=root->a2=root->a3=root->a4=root->a5=root->a6=root->a7=root->a8=root->a9=NULL;
    return root;
}

int minmax(char board[],char turn,int n)
{
    int i,a[9],v=0;
    char board2[9];
    node *root=NULL;
    for(i=0;i<9;i++)
    {
        board2[i]=board[i];
        if('1'<=board[i]&&board[i]<='9')
        {
            a[i]=i;
            v++;
        }
        else
            a[i]=-1;
    }
    for(i=0;i<9;i++)
        printf("%c\n",board2[i]);
    int b[v],j=0;
    for(i=0;i<9;i++)
    {
        if(a[i]==-1)
            continue;
        else
        {
            b[j]=a[i];
            j++;
        }

    }
    printf("\n");
    for(i=0;i<v;i++)
        printf("%d\n",b[i]);
    printf("v=%d\n",v);
    if(root==NULL)
        root=getnew(board2);
    //for(i=0;i<9;i++)
        //printf("%c",root->board1[i]);
    for(i=0;i<v;i++)
        {
            int s=b[i];
            printf("s=%d\n",s);
            if(i==0)
                root->a1=newcreat(board,s,turn);
            else if(i==1)
                root->a2=newcreat(board,s,turn);
            else if(i==2)
                root->a3=newcreat(board,s,turn);
            else if(i==3)
                root->a4=newcreat(board,s,turn);
            else if(i==4)
                root->a5=newcreat(board,s,turn);
            else if(i==5)
                root->a6=newcreat(board,s,turn);
            else if(i==6)
                root->a7=newcreat(board,s,turn);
            else if(i==7)
                root->a8=newcreat(board,s,turn);
            else
                root->a9=newcreat(board,s,turn);
        }
    for(i=0;i<9;i++)
    {
        printf("%c\n",root->a3->board1[i]);
    }
    return 0;

}
int Wins(char board[9],char a)
{
    if(a==board[0]&&a==board[1]&&a==board[2])
    {
        return 1;
    }
    else if(a==board[3]&&a==board[4]&&a==board[5])
    {
        return 1;
    }
    else if(a==board[6]&&a==board[7]&&a==board[8])
    {
        return 1;
    }
    else if(a==board[0]&&a==board[3]&&a==board[6])
    {
        return 1;
    }
    else if(a==board[1]&&a==board[4]&&a==board[7])
    {
        return 1;
    }
    else if(a==board[2]&&a==board[5]&&a==board[8])
    {
        return 1;
    }
    else if(a==board[0]&&a==board[4]&&a==board[8])
    {
        return 1;
    }
    else if(a==board[2]&&a==board[4]&&a==board[6])
    {
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
        return 1;
    else
        return 0;
}
void main()
{
    int n=5;
    char turn='c';
     //node *root=NULL;
     int s=minmax(board,turn,n);
     getche();


}
