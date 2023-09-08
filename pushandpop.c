#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void push(int);
void pop();
int top=0;
int stack[4];
int main()
{
    int choice,item;
    char ch;
    while(1)
    {
    printf("\nPush-1\n");
    printf("Pop-2\n");
    printf("Display-3\n");
    printf("Exit-4\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter the item:");
                scanf("%d",&item);
                push(item);
                break;
        case 2: pop();
                break;
        case 3:dis();
            break;
        case 4:exit(1);
        break; 
    }
    }
   
    return 0;
}
void push(int item)
{
    if(top==4)
    {
        printf("stack is full");
    }
    else
    {
        stack[top]=item;
        top=top+1;
        
    }
}
void pop()
{
    int item;
    if (top==0)
    {
        printf("Stack is empty");
    }
    
    else
    {
        printf("%d\n",top);
         top=top-1;
        item=stack[top];
       printf("item popped from the stack %d",item);
    }
    
    
}
void dis()
{
    int i;
    printf("The current stack is\n");
    for(i=top-1;i>=0;i--)
    {
        printf("%d\t",stack[i]);
    }
}
    
