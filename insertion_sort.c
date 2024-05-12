
#include<stdio.h>

int insertionsort(int n,int a[])
{
    int temp,i,j;
    for(i=0;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
}

void display(int n, int a[])
{
    int i;
    printf("After Sorting: \n");
    for(i=0;i<n;i++)
    {
        printf(" %d",a[i]);
    }
}

void main()
{
    int n,i;
    int a[10];
    printf("How many numbers?\n");
    scanf("%d",&n);
    printf("Enter the elements: \n");
    for(i=0;i<n;i++)
    {
        scanf(" %d",&a[i]);
    }
    insertionsort(n,a);
    display(n,a);
}