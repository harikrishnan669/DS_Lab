/*Implementing polynomial multiplication using linked list*/
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

void multiply(struct poly* head1,struct poly* head2,struct poly* head3)
{
    struct poly* pptr,*qptr;
    float coeff;
    int exp;
    pptr=head1->link;
    //qptr=head2->link;
    while (pptr != NULL)
    {
        qptr = head2->link;
        while (qptr != NULL)
        {
            coeff = pptr->coeff * qptr->coeff;
            exp = pptr->exp + qptr->exp;
            insert(head3, coeff, exp);
            qptr = qptr->link;
        }
        pptr = pptr->link;
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
    multiply(phead,qhead,rhead);
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
