#include<stdio.h>
#include<stdlib.h>
typedef struct node1
{
    int data;
    struct node *left;
    struct node *right;
}node;
node *create()
{
     node *ptr;
    int num;
    printf("Enter the value(Input -1 if there is no data):");
    scanf("%d",&num);
    if(num==-1)
    {
        return NULL;
    }
    ptr=(node*)malloc(sizeof(node));
    ptr->data=num;
    if(num<ptr->data)
    {
        ptr->left=create();
    }
    else
    {
        ptr->right=create();
    }
    return ptr;
}
void inorder(node *ptr)
{
if(ptr!=NULL)
{
    inorder(ptr->left);
    printf("\t%d",ptr->data);
    inorder(ptr->right);
}
}
void preorder(node *ptr)
{
    if(ptr!=NULL)
    {
        printf("\t%d",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void postorder(node *ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("\t%d",ptr->data);
    }
}
int main()
{
    int choice;
    node *root;
    root=create();
    printf("1-INORDER\n");
    printf("2-PREORDER\n");
    printf("3-POSTORDER\n");
    printf("4-EXIT\n");
    while(1)
    {
    printf("\nEnter the choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("The inorder is");
               inorder(root);
               break;
        case 2:printf("The preorder is");
               preorder(root);
               break;
        case 3:printf("The post order is");
               postorder(root);
               break;
        case 4:exit(1);
               break;
    }
    }
}
