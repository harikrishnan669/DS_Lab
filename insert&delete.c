#include<stdio.h>
#include <stdlib.h>
void insert(int);
void del();
void display();
int front=-1;
int rear=-1;
int queue[5];
int main()
{
    int choice,item;
    while(1)
    {
        printf("\nInsert-1\n");
        printf("Delete-2\n");
        printf("Display-3\n");
        printf("Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the item:");
                    scanf("%d",&item);
                    insert(item);
                    break;
            case 2: del();
                    break;
            case 3: display();
                    break;
            case 4: exit(1);
                    break;
        }
    }
}
    void insert(int item)
    {
        if(rear==4)
        {
            printf("Queue is full");
        }
        else
        {
            queue[rear]=item;
            rear=rear+1;
        }
    }
    void del()
    {
        int item;
        if(front==rear)
        {
            printf("Queue is empty");
        }
        else
        {
            item=queue[front];
            front=front+1;
        }
    }
    void display()
    {
        int i;
        for(i=front;i<=rear-1;i++)
        {
            printf("%d",queue[i]);
        }
    }
