#include<stdio.h>
#include<stdlib.h>
struct list
{
    int data;
    struct list * link;
};
typedef struct list node;
int main()
{
    int info;
    node * head=NULL;
    node * temp;
     printf("Enter -999 to stop the creation of linked list\n");
     while(1)
     {
         printf("enter the data \n");
        scanf("%d",&info);
        
        if(info==-999)
        {break;}
        
        else if(head==NULL)
         {
            
             temp=(struct node*)malloc(sizeof(node));
             temp->data=info;
             temp->link=NULL;
             head=temp;
         }
         else
         {
             temp->link=(struct node*)malloc(sizeof(node));
             temp->link->data=info;
             temp=temp->link;
             
         }
     }
     temp->link=NULL;
     
     while(head!=NULL)
     {
         printf(" %d  ",head->data);
         head=head->link;
     }
}
