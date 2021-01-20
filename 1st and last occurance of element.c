#include <stdio.h>

void mergesort(int a[],int low,int mid,int high)
{
    int i,j,k;

    int l=mid-low+1;    //calculating the size of first sub array
    int r=high-mid;     //calculating the size of second sub array

    int left[l], right[r];  //creating two new array 

    for(i=0;i<l;i++)
        left[i]=a[low+i];   /*copy the value into first new 
                            array from first part of array*/
    
    for(j=0;j<r;j++)
        right[j]=a[mid+1+j];    //copy the value into second new 
        i=0;                   // array from second part of array
        j=0;
        k=low;

    while(i<l&&j<r)             //comparing the value of both new array
    {                           //and inserting the smaller value into original array
        if(left[i]<=right[j])
        {
            a[k]=left[i++];
          
        }
        else
        {
            a[k]=right[j++];
           
        }
        k++;
    }
    while(i<l)              //copy the remaining value of first                         
    {                       //array into original array(if value is left)
        a[k++]=left[i++];
       
    }

    while(j<r)              //copy the remaining value of second                     
    {                       //array into original array(if value is left)
        a[k++]=right[j++];
       
    }   
}

void merge(int a[],int low,int high)    //dividing the array in two                                        
{                                       //part(low..mid) and (mid+1...high)
    if(low<high)
    {
        int mid=(low+high)/2;
        merge(a,low,mid);   
        merge(a,mid+1,high);

        mergesort(a,low,mid,high); //calling the function for sorting two sub array
    }
    else
    {
        return;
    }
}

int findfirst(int a[],int low, int high, int x)
{                                   //finding the first 
    int mid;                        //occurance of number
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x<a[mid])
            high=mid-1;
        else if(x>a[mid])
            low=mid+1;
        else if(a[mid]==a[mid-1])
            high=mid-1;
        else
            return(mid);
    }
    return(-1);
}

int findlast(int a[],int low, int high, int x)
{                                       //function for finding 
    int mid;                            //last occurance
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x<a[mid])
            high=mid-1;
        else if(x>a[mid])
            low=mid+1;
        else if(a[mid]==a[mid+1])
            low=mid+1;
        else
            return(mid);
    }
    return(-1);
}

int  main() 
{
    int i=0,x;
    int a[10];

    printf("enter 10 number in an array \n");
    for(i=0;i<10;i++)
    {
        printf("enter value\t");
        scanf("%d",&a[i]);
    }
    
    printf("enter value to search\t");
    scanf("%d",&x);

    printf("\nbefore sorting\n"); //printing value before sorting
    for(i=0;i<10;i++)
    printf("%d,",a[i]);

    merge(a,0,9); //calling merge function

    printf("\nafter sorting\n");//printing value after sorting
    for(i=0;i<10;i++)
    printf("%d,",a[i]);
    
    int first=findfirst(a,0,9,x);//find the first occurance of number
    int last=findlast(a,0,9,x); //find the last occurance of number
    
    if(first>=0 && last>=0)         //printing the position
    {
        printf("\n\nvalue found at %d position",1+first);
        printf("\n\nvalue found at %d position",1+last);
    }
    else
        printf("\n\nvalue not found");
    
    return 0;
}