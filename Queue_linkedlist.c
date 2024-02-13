#include<stdio.h>
#include<stdlib.h>
typedef struct node1
{
    int data;
    struct node1*link;
}node;
node* f=NULL;
node*r=NULL;
void enqueue()
{
    node*new;
    int x;
    new=(node*)malloc(sizeof(node));
    printf("Enter the data to be inserted:");
    scanf("%d",&x);
    if(f==NULL && r==NULL)
    {
    new->data=x;
    new->link=NULL;
    f=r=new;
    }
    else
    {
     r->link=new;
     new->data=x;
     new->link=NULL;
     r=new;
    }
}
void display()
{
    if(f==NULL && r==NULL)
    {
        printf("Queue underflow");
    }
    else
    {
        node*ptr=f;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
}
void dequeue()
{
    if(f==NULL && r==NULL)
    {
        printf("Queue underflow");
    }
    struct node*ptr=f;
    printf("Dlelted element is:%d\n",f->data);
    f=f->link;
    free(ptr);
}
void main()
{
    int choice;
    while(1)
    {
    printf("1:Insert\n2:Delete\n3:Display\n");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue();
                    break;
            case 2:dequeue();
                    break;
            case 3:display();
                    break;
            default:printf("Enter a valid choice");
        }
    }
    }
}
