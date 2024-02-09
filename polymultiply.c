#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff,exp;
    struct node*link;
};
struct node* ph,*qh,*rhead;
struct node* arrange(struct node*);
struct node* rdpoly()
{
    int n;
    struct node*ptr;struct node*head=NULL;
    printf("Enter the no. of terms of the polynomial:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        struct node*ne=malloc(sizeof(struct node));
        printf("Enter the coeff%d and exp%d:",i,i);
        scanf("%d %d",&ne->coeff,&ne->exp);
        ne->link=NULL;
        if(head==NULL)
        {
            head=ne;
            ptr=head;
        }
        else
        {
            ptr->link=ne;
            ptr=ne;
        }
    }
     return head;
}
void display(struct node*head)
{
    struct node* t=head;
    if(t==NULL)
    {
        printf("Empty");
    }
    else
    {
        while(t->link!=NULL)
        {
            printf("%dx^%d+",t->coeff,t->exp);
            t=t->link;
        }
        printf("%dx^%d",t->coeff,t->exp);
    }
}
struct node*multi()
{
    struct node*p,*q,*r,*head=NULL;
    p=ph;q=qh;
    while(p!=NULL)
    {
        while(q!=NULL)
        {
            struct node*ne=malloc(sizeof(struct node));
            ne->coeff=p->coeff*q->coeff;
            ne->exp=p->exp+q->exp;
            ne->link=NULL;
            if(head==NULL)
            {
                head=ne;
                r=ne;
            }
            else
            {
                r->link=ne;
                r=ne;
            }
            q=q->link;
        }
        p=p->link;
        q=qh;
    }
    return head;
}
/*struct node *arrange(struct node *h)
{
    struct node *p = h, *prev = h;

    while (p != NULL)
    {
        struct node *q = p->link;

        while (q != NULL)
        {
            if (p->exp == q->exp)
            {
                p->coeff = p->coeff + q->coeff;
                prev->link = q->link;
                free(q);
                q = prev->link;
            }
            else
            {
                prev = prev->link;
                q = q->link;
            }
        }

        p = p->link;
        prev = h; // Reset the prev pointer for the next iteration
    }

    return h;
}*/

/*struct node*arrange(struct node*h)
{
    struct node*p=h,*prev=h;
    struct node*q=h->link;
    while(p!=NULL)
    {
        prev=p;
        q=p->link;
        while(q!=NULL)
        {
            if(p->exp==q->exp)
            {
                p->coeff=p->coeff+q->coeff;
                prev->link=q->link;
                free(q);
                q=prev->link;
            }
            else
            {
                prev=prev->link;q=q->link;
            }
            p=p->link;
        }
    }
    return h;
}*/
void main()
{
    printf("Enter the details of first polynomial\n");
    ph=rdpoly();
    printf("Enter the details of first polynomial\n");
    qh=rdpoly();
    printf("First polynomial:");
    display(ph);
    printf("\n");
    printf("First polynomial:");
    display(qh);
    printf("\n");
    printf("Product:\n");
    rhead=multi();
    rhead=arrange(rhead);
    display(rhead);
}
struct node* arrange(struct node* h)
{
    struct node* p = h;

    while (p != NULL)
    {
        struct node* q = p->link;
        struct node* prev = p;

        while (q != NULL)
        {
            if (p->exp == q->exp)
            {
                p->coeff = p->coeff + q->coeff;
                prev->link = q->link;
                free(q);
                q = prev->link;
            }
            else
            {
                prev = q;
                q = q->link;
            }
        }

        p = p->link;
    }

    return h;
}
