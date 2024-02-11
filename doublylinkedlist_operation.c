#include<stdio.h>
#include<stdlib.h>
typedef struct node1
{
    int data;
    struct node1 *next;
    struct node1 *prev;
}node;
    node *header;
void create()
{
    node *ptr,*temp;
    int num;
    header=(node*)malloc(sizeof(node));
    header->data=0;
    header->next=NULL;
    header->prev=NULL;
    ptr=header;
    printf("Enter number");
    scanf("%d",&num);
    while(num!=-999)
    {
        temp=(node*)malloc(sizeof(node));
        temp->data=num;
        temp->next=NULL;
        ptr->next=temp;
        temp->prev=ptr;
        printf("Enter -999 to exit");
        scanf("%d",&num);
        ptr=temp;
    }
}
void insertatbegin()
{
    node *temp;
    int num;
    node *ptr;
    ptr=header;
    printf("Enterthe number\n");
    scanf("%d",&num);
    temp=(node*)malloc(sizeof(node));
    temp->data=num;
    temp->next=NULL;
    temp->next=ptr->next;
     ptr->next=temp;
     ptr=temp;
    
}
void insertatend()
{
    node *ptr;
    int num;
    node *temp;
    ptr=header;
    temp=(node*)malloc(sizeof(node));
    printf("Enter data");
    scanf("%d",&num);
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    temp->data=num;
    temp->next=NULL;
    ptr->next=temp;
    temp->prev=ptr;
    
}
void display()
{
    node *ptr;
    ptr=header->next;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
void deletefrombegin()
{
    node *temp,*ptr;
    ptr=header;
    temp=ptr->next;
    ptr->next=temp->next;
    temp->next->prev=ptr;
    free(temp);
}
void deletefromend()
{
    node *ptr,*temp;
    ptr=header;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=NULL;
    free(temp);
}
int main()
{
    int choice;
    do
    {
        printf("Enter your choice\n");
        printf("1-create\n");
        printf("2-Insert at beginning\n");
        printf("3-insert at end\n");
        printf("4-Deletefrom begin\n");
        printf("5-DElete from end\n");
        printf("6-Display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:create();
            break;
            case 2:insertatbegin();
            break;
            case 3:insertatend();
            break;
            case 4:deletefrombegin();
            break;
            case 5:deletefromend();
            break;
            case 6:display();
            break;
            default:
            break;
            
        }
    }while(choice<=6);
}