#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data ;
    struct node *link;
};
void print(struct node *);
int main()
{
    struct node *head=NULL, *current=NULL ;
   
    head=(struct node *)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
  
  current=(struct node*)malloc(sizeof(struct node));
  current->data=55;
  current->link=NULL;
  head->link=current;
  print(head);
}
void print(struct node *head)

{
    struct node *current=NULL;
    if(head==NULL)
    {
        printf("List is empty");
    }
    current=head;
    while(current!=NULL)
    {
        printf("%d",current->data);
        current=current->link;
    }
    
}
