#include<stdio.h>
int main()
{
    int n,sort[10],i,j,temp=0;
    printf("Enter the limit:");
    scanf("%d",&n);
    printf("Enter the numbers to be sorted:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&sort[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(sort[j]>sort[j+1])
            {
                temp=sort[j];
                sort[j]=sort[j+1];
                sort[j+1]=temp;
            }

        }

    }
    printf("The sorted order is");
    for(i=0;i<n;i++)
    {
    printf("\n%d",sort[i]);
    }
    return 0;
}