#include<stdio.h>
int main()
{
    int num[30],i,j,n,temp=0;
    printf("Enter the limit of the elements:");
    scanf("%d",&n);
    printf("Enter the elements in the array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(i=0;i<(n-1);i++)
    {
        for(j=0;j<(n-i-1);j++)
        {
            if(*(num+j)>*(num+(j+1)))
            {
            temp=*(num+j);
            *(num+j)=*(num+(j+1));
            *(num+(j+1))=temp;
            }
        }
    }
    printf("The sorted order is");
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(num+i));
    }
    
}
