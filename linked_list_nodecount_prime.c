#include<stdio.h>
#include<stdlib.h>
typedef struct node1
{
    int data;
    struct node1*link;
}node;
node*header;
void create()
{
    int num;
    node *temp,*ptr;
    header=(node*)malloc(sizeof(node));
    header->data=0;
    header->link=NULL;
    ptr=header;
    printf("Enter numbers to create the list:");
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
void count()
{
    node*ptr;
    ptr=header;
    ptr=ptr->link;
    int count=0;
    while(ptr!=NULL)
    {
        ptr=ptr->link;
        count=count+1;
    }
    printf("\nThe count of node is: %d",count);
    
}
void display()
{
    node*ptr;
    ptr=header;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
        printf("%d\t",ptr->data);
    }
}
void prime()
{
    node*ptr;
    ptr=header;
    ptr=ptr->link;
    int count1=0;
    while(ptr!=NULL)
    {
        if(isprime(ptr->data)==1)
        {
            printf("%d\t",ptr->data);
            count1=count1+1;
        }
         ptr=ptr->link;
    }
    printf("The count value of prime numbers is %d",count1);
}
int isprime(int num)
{
    int i;
    for(i=2;i<=(num/2);i++)
    {
        if(num%i==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
int main()
{
    void create();
    int choice;
    while(1)
    {
        printf("1-To create the list\n");
        printf("\n2-To count the number of node\n");
        printf("\n3-To display elemets\n");
        printf("\n4-To find prime\n");
        while(1)
        {
            printf("\nEnter the choice:");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:create();
                       break;
                case 2:count();
                       break;
                case 3:display();
                       break;
                case 4:prime();
                       break;
            }
        }
        return 0;
    }
}
