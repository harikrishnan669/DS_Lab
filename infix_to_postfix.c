#include<stdio.h>
char stack[30];
int top=-1;
int priority(char);
void push(char x)
{
    top=top+1;
    stack[top]=x;
}
char pop()
{
    char ch;
    ch=stack[top];
    top=top-1;
    return ch;
}
int main()
{
    char exp[30],x;
    int i=1;
    int z;
    printf("Enter the expression\n");
    scanf("%s",exp);
    x=exp[0];
    while(x!='\0')
    {
        if(x>='a' && x<='b')
        {
            printf("%c",x);
        }
        else if(x=='(')
        {
            push(x);
        }
        else if(x==')')
        {
            z=pop();
        while(z!='(')
            {
            printf("%c",z);
            z=pop();
             }
        }
        else
        {
            while(priority(stack[top])>=priority(x))
            {
                printf("%c",pop());
            }
            push(x);
        }
            x=exp[i++];
    }
        while(top!=-1)
        {
            printf("%c",pop());
        }
        return 0;
    }
    int priority(char ch)
    {
        if(ch=='(')
        {
            return 0;
        }
        if(ch=='+'||ch=='-')
        {
            return 1;
        }
        if(ch=='*'||ch=='/')
        {
            return 2;
        }
        if(ch=='^')
        {
            return 3;
        }
    }
