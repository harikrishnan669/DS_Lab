#include<stdio.h>
int main()
{
    int a[30],n,i, *small;
    printf("Enter the limit of the elements:");
    scanf("%d",&n);
    printf("Enter the elements of the array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    small=&a[0];
    for(i=1;i<n;i++)
    {
     if(*(a+i)<*small)
     {
         *small=*(a+i);
     }
    }
    printf("The smallest elements in the array is %d",*small);
}
