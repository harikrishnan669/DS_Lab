
#include<stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[],int low,int high)
{
    int i=low;
    int j=high;
    int pivot=low;

    while(i<j)
    {
        while(array[i] <= array[j])
            i++;

        while(array[j] > array[pivot])
            j--;

        if(i<j)
        {
            swap(&array[i],&array[j]);
        }
    }
    swap(&array[j],&array[pivot]);
    return j;
}

void quicksort(int array[],int low,int high)
{
    if(low<high)
    {
        int j=partition(array,low,high);
        quicksort(array,low,j-1);
        quicksort(array,j+1,high);
    }
}

void display(int n, int array[])
{
    int i;
    printf("After Sorting: \n");
    for(i=0;i<n;i++)
    {
        printf(" %d",array[i]);
    }
}

void main()
{
    int n,i;
    int array[10];
    printf("How many numbers?\n");
    scanf("%d",&n);
    printf("Enter the elements: \n");
    for(i=0;i<n;i++)
    {
        scanf(" %d",&array[i]);
    }
    quicksort(array,0,n-1);
    display(n,array);
}