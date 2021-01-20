

#include <stdio.h>
void selectionsort(int [],int);

void selectionsort(int arr[],int n)
{
    int i=0,min,j,temp;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    
    printf("\narray after sorting\n");
    for(i=0;i<10;i++)
        printf("%d,",arr[i]);
        
}

int main()
{
    int arr[10],i;

    printf("enter value\n");
    for(i=0;i<10;i++)
    scanf("%d",&arr[i]);
    
    printf("array before sorting\n");
    for(i=0;i<10;i++)
        printf("%d,",arr[i]);
    
    selectionsort(arr,10);

    return 0;
}


