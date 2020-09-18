#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node* getnewNode(int b)
{
    node* root=(node*)malloc(sizeof(node));
    root->next=NULL;
    root->data=b;
    return root;
}
node* insert(node* root,int b)
{
    if(root==NULL)
        root=getnewNode(b);
    else
        root->next=insert(root->next,b);
    return root;
}
void main()
{
    node *root=NULL;
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,5);
    while(root!=NULL)
    {
        printf("Data = %d\n",root->data);
        root=root->next;
    }

}
