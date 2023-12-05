#include<stdio.h>
#define MAX 10

int deque[MAX];
int f=-1, r=-1;

void insert_rear();
void insert_front();
int delete_rear();
int delete_front();
void display();

void main()
{
 int choice;
 printf("\n1.Insert at rear ");
  printf("\n2.Insert at front ");
  printf("\n3.Delete from rear ");
  printf("\n4.Delete from front ");
  printf("\n5.Display ");
 do
 {

  printf("\n\nEnter your choice ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
    insert_rear();
    break;
   case 2:
    insert_front();
    break;
   case 3:
    delete_rear();
    break;
   case 4:
    delete_front();
    break;
   case 5:
    display();
    break;
   case 6: printf("Invalid choice\n");
         break;
  }
 }while(choice<=5);

}


void insert_rear()
{
 int item;
 printf("\nEnter the value to be added ");
 scanf("%d",&item);
 if( (f==0 && r==MAX-1) || (f==r+1) )
 {
  printf("\nOVERFLOW");
 }
 if(f==-1)       
 {
  f=0;
  r=0;
 }
 else
 {
  if(r==MAX-1)
   r=0;
  else
   r=r+1;
 }
 deque[r]=item;
}


void insert_front()
{
 int item;
 printf("\nEnter the value to be added ");
 scanf("%d",&item);
 if( (f==0 && r==MAX-1) || (f==r+1) )
 {
  printf("\nOVERFLOW");
 }
 if(f==-1)      
 {
  f=0;
  r=0;
 }
 else
 {
  if(f==0)
   f=MAX-1;
  else
   f=f-1;
 }
 deque[f]=item;
}

int delete_rear()
{
 if(f==-1)
 {
  printf("\nUNDERFLOW");
 }
 int item;
 item=deque[r];

 if(f==r)         
 {
  f=-1;
  r=-1;
 }
 else
 {
  if(r==0)
   r=MAX-1;
  else
   r=r-1;
 }
 return item;
}

int delete_front()
{
 if(f==-1)
 {
  printf("\nUNDERFLOW");
 }
 int item;
 item=deque[f];

 if(f==r)         
 {
  f=-1;
  r=-1;
 }
 else
 {
  if(f==MAX-1)
   f=0;
  else
   f=f+1;
 }
}
void display()
{
    int i;
    if(f==-1)
      printf("Queue Empty\n");
    else if(f<=r)
    {
      for(i=f;i<=r;i++)
        printf("%d\t",deque[i]);
      printf("\n");
    }
    else
    {
      for(i=f;i<MAX;i++)
        printf("%d\t",deque[i]);
      for(i=0;i<=r;i++)
        printf("%d\t",deque[i]);
      printf("\n");
    }
}