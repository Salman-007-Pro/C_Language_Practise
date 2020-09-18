#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
   struct node *left,*right;
}node;
node* getnewNode(int a)
{
    node* root=(node*)malloc(sizeof(node));
    root->data=a;
    root->left=root->right=NULL;
    return root;
}
node* insert(node* root,int b)
{
    if(root==NULL)
        root=getnewNode(b);
    else if(b<=root->data)
        root->left=insert(root->left,b);
    else
        root->right=insert(root->right,b);
    return root;
}
int search(node* root,int b)
{
    if(root==NULL)
        return 0;
    else if(root->data==b)
        return 1;
    else if(b<=root->data)
        return search(root->left,b);
    else
        return search(root->right,b);

}
void main()
{
    node *root=NULL;
    int n;
    root=insert(root,5);
    root=insert(root,4);
    root=insert(root,3);
    root=insert(root,8);
    printf("enter the number = ");
    scanf("%d",&n);
    int s=search(root,n);
    if(s==0)
        printf("number is not found");
    else
        printf("Number is found");
}
