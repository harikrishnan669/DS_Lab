/*Implementing polynomial addition using Linked List*/
#include <stdio.h>
#include <stdlib.h>
struct poly
{
    float coeff;
    int exp;
    struct poly* link;
};

void insert(struct poly* head,float coeff,int exp)
{
    struct poly* new,*ptr;
    new=malloc(sizeof(struct poly));
    new->coeff=coeff;
    new->exp=exp;
    new->link=NULL;
    if(head->link==NULL)
    {
        head->link=new;
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=new;
    }
}

void display(struct poly* head)
{
    struct poly* ptr;
    ptr = head->link;
    while (ptr != NULL)
    {
        printf("%.2fx^%d", ptr->coeff, ptr->exp);
        ptr = ptr->link;
        if (ptr != NULL)
        {
            printf(" + ");
        }
    }
}

void sum(struct poly* head1,struct poly* head2,struct poly* head3)
{
    struct poly* pptr,*qptr,*rptr,*new;
    pptr=head1->link;
    qptr=head2->link;
    rptr=head3;
    while(pptr!=NULL && qptr!=NULL)
    {
        if(pptr->exp==qptr->exp)
        {
            new=malloc(sizeof(struct poly));
            new->link=NULL;
            rptr->link=new;
            rptr=new;
            rptr->coeff=pptr->coeff + qptr->coeff;
            rptr->exp=pptr->exp;
            pptr=pptr->link;
            qptr=qptr->link;  
        }
        else if(pptr->exp>qptr->exp)
        {
            new=malloc(sizeof(struct poly));
            new->link=NULL;
            rptr->link=new;
            rptr=new;
            rptr->coeff=pptr->coeff;
            rptr->exp=pptr->exp;
            pptr=pptr->link;
        }
        else
        {
            new=malloc(sizeof(struct poly));
            new->link=NULL;
            rptr->link=new;
            rptr=new;
            rptr->coeff=qptr->coeff;
            rptr->exp=qptr->exp;
            qptr=qptr->link;
        }
    }
    while(pptr!=NULL)
    {
        new=malloc(sizeof(struct poly));
        rptr->link=new;
        rptr=new;
        rptr->coeff=pptr->coeff;
        rptr->exp=pptr->exp;
        rptr->link=NULL;
        pptr=pptr->link;
    }
    while(qptr!=NULL)
    {
        new=malloc(sizeof(struct poly));
        rptr->link=new;
        rptr=new;
        rptr->coeff=qptr->coeff;
        rptr->exp=qptr->exp;
        rptr->link=NULL;
        qptr=qptr->link;
    }
}

void main()
{
    int i,m,n,exp;
    float coeff;
    struct poly* phead,*qhead,*rhead;
    phead=malloc(sizeof(struct poly));
    phead->link=NULL;
    qhead=malloc(sizeof(struct poly));
    qhead->link=NULL;
    rhead=malloc(sizeof(struct poly));
    rhead->link=NULL;
    printf("Enter the number of terms of first polynomial : ");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        printf("Enter the coefficent : ");
        scanf("%f",&coeff);
        printf("Enter the exponent : ");
        scanf("%d",&exp);
        insert(phead,coeff,exp);
    }
    printf("Enter the number of terms of second polynomial : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the coefficent : ");
        scanf("%f",&coeff);
        printf("Enter the exponent : ");
        scanf("%d",&exp);
        insert(qhead,coeff,exp);
    }
    sum(phead,qhead,rhead);
    printf("The first polynomial : ");
    display(phead);
    printf("\n");
    printf("The second polynomial : ");
    display(qhead);
    printf("\n");
    printf("The Resultant polynomial : ");
    display(rhead);
    printf("\n");
}
