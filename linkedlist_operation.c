#include<stdio.h>
#include<stdlib.h>
typedef struct node1
{
    int data;
    struct node1*link;
}node;
node *header;
void create()
{
    int num;
    node *temp,*ptr;
    header=(node*)malloc(sizeof(node));
    header->data=0;
    header->link=NULL;
    ptr=header;
    printf("Enter numbers to create list:");
    scanf("%d",&num);
    while(num!=-999)
    {
        temp=(node*)malloc(sizeof(node));
        temp->data=num;
        temp->link=NULL;
        ptr->link=temp;
        ptr=temp;
        printf("Enter -999 to stop the creation of the list:");
        scanf("%d",&num);
    }
}
void display()
{
    node *ptr;
    ptr=header;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
        printf("%d\t",ptr->data);
    }
}

void insertfront()
{
    int num;
    node*new,*ptr;
    if(new==NULL)
    {
        printf("No insertion is possible");
    }
    else
    {
        ptr=header;
        new=(node*)malloc(sizeof(node));
        printf("Enter the number:");
        scanf("%d",&num);
        new->data=num;
        new->link=NULL;
        new->link=ptr->link;
        ptr->link=new;
    }
}
void insertAtanyposition()
{
    int num,key;
    node*new,*ptr;
    if(new==NULL)
    {
        printf("No insertion is possible");
    }
    else
    {
        ptr=header;
        printf("Enter the key:");
        scanf("%d",&key);
    }
    while(ptr->data!=key)
    {
        ptr=ptr->link;
    }
    printf("Enter the number:");
    scanf("%d",&num);
    new=(node*)malloc(sizeof(node));
    new->data=num;
    new->link=NULL;
    new->link=ptr->link;
    ptr->link=new;
}
void insertAtlast()
{
    int num;
    node *new,*ptr;
    if(new==NULL)
    {
        printf("No insertion is not possible");
    }
    else
    {
        ptr=header;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link; 
        }
    }
    printf("Enter the num:");
    scanf("%d",&num);
    new=(node*)malloc(sizeof(node));
    new->data=num;
    new->link=NULL;
    ptr->link=new;
}
void deletefrombegining()
{
    node*ptr;
    ptr=header;
    if(ptr==NULL)
    {
        printf("The list is empty");
    }
    else
    {
    ptr=ptr->link;
    header->link=ptr->link;
    free(ptr);
    }
}
void deletefromanyposition()
{
    int key;
    node *ptr,*prev;
    ptr=header;
    prev=header;
    if(ptr==NULL)
    {
        printf("The list is empty");
    }
    else
    {
        printf("Enter the key:");
        scanf("%d",&key);
        while(ptr->data!=key)
        {
            prev=ptr;
            ptr=ptr->link;
        }
        prev->link=ptr->link;
        free(ptr);
    }
}
void deletefromlast()
{
    node *ptr,*prev;
    ptr=header;
    prev=header;
    if(ptr==NULL)
    {
        printf("The list is empty");
    }
    else
    {
        while(ptr->link!=NULL)
        {
            prev=ptr;
            ptr=ptr->link;
        }
        prev->link=NULL;
        free(ptr);
    }
}
int main()
{
    void create();
    int choice;
    while(1)
    {
        printf("\n1-To create the list\n");
        printf("2-Insert node at front\n");
        printf("3-Insert at any position\n");
        printf("4-Insert at last\n");
        printf("5-Delete from begining\n");
        printf("6-Delete from any position\n");
        printf("7-Delete from last\n");
        printf("8-To display the list\n");
        printf("9-exit\n");
        while(1)
        {
        printf("\nEnter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:create();
            break;
            case 2:insertfront();
            break;
            case 3:insertAtanyposition();
            break;
            case 4:insertAtlast();
            break;
            case 5:deletefrombegining();
            break;
            case 6:deletefromanyposition();
            break;
            case 7:deletefromlast();
            break;
            case 8:display();
            break;
            case 9:exit(1);
            break;
        }
        }
        return 0;
    }
}
