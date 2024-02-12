#include<stdio.h>
#include<stdlib.h>
typedef struct node1
{
    int data;
    struct node1 *link;
}node;
node *top;
void push()
{
    int num;
    node *new;
    printf("Enter data");
    scanf("%d",&num);
    new=(node*)malloc(sizeof(node));
    new->data=num;
    new->link=top;
    top=new;
}
void pop()
{
    if(top==NULL)
    {
        printf("Stack empty");
        return;
    }
    node *temp=top;
    top=top->link;
    free(temp);
}
void display()
{
    if(top==NULL)
    {
        printf("Stack empty");
        return;
    }
    node *temp=top;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("1-push\n");
        printf("2-pop\n");
        printf("3-Display\n");
        while(1)
        {
        printf("Enter your choice\n");    
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
        }
    }
    }
}
