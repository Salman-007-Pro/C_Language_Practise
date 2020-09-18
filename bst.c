#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *l,*r;
}node;
node* getnewNode(int a)
{
    node* root=(node*)malloc(sizeof(node));
    root->data=a;
    root->l=root->r=NULL;
    return root;
}
node* insert(node* root,int b)
{
    if(root==NULL)
        root=getnewNode(b);
    else if(b<=root->data)
        root->l=insert(root->l,b);
    else
        root->r=insert(root->r,b);
    return root;
}
int search(node* root,int b)
{
    if(root==NULL)
        return 0;
    else if(root->data==b)
        return 1;
    else if(b<=root->data)
        return search(root->l,b);
    else
        return search(root->r,b);

}
void main()
{
    int n;
    node *root=NULL;
    root=insert(root,6);
    root=insert(root,6);
    root=insert(root,6);
    printf("Enter the number = ");
    scanf("%d",&n);
    int s=search(root,n);
    if(s==1)
        printf("Number is found\n");
    else
        printf("Number is not found\n");

}
