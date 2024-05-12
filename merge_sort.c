
#include <stdio.h>

int arr[25],b[25];

void Merge(int arr[],int low,int mid,int high)
{
    int i,j,k=0,p;
    i=low;
    j=mid+1;
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            b[k]=arr[i];
            k++;i++;
        }
        else if(arr[j] < arr[i])
        {
            b[k]=arr[j];
            k++;j++;
        }
    }
    while(i <= mid)
    {
        b[k]=arr[i];
        i++;k++;
    }
    while(j <= high)
    {
        b[k]=arr[j];
        j++;k++;
    }
    for (p=0;p<=high-low;p++)
    {
        arr[low+p]=b[p];
    }
}

void MergeSort(int arr[],int low,int high)
{
    int mid;
    if(low < high)
    {
        mid=(low + high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);

    }
}
void main()
{
    int n;
    printf("How many elements in array ? : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    MergeSort(arr,0,n-1);
    printf("After Sorting : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}