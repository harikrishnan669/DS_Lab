#include<stdio.h>
#include<stdlib.h>
typedef struct node1
{
    int data;
    struct node *left;
    struct node *right;
}node;
int key;
int flag=0;
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
void search(node *ptr)
{
if(ptr!=NULL)
{
    search(ptr->left);
    if(ptr->data==key)
    {
        flag=1;
        return flag;
    }
   search(ptr->right);
}
}
int main()
{
    int choice;
    node *root;
    root=create();
    printf("Enter the element to be searched:");
    scanf("%d",&key);
    search(root);
    if(flag==1)
    {
        printf("The element is present in the tree");
    }
    else
    {
        printf("The element is not present in the tree");
    }
}
