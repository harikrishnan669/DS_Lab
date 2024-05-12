
#include<stdio.h>

int selectionsort(int n,int a[])
{
    int temp,i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
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
    selectionsort(n,a);
    display(n,a);
}