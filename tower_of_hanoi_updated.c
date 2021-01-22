#include<stdio.h> 
void towers_hanoi(int n) 
{ 
 for(int x=1;x<(1<<n);x++)
 {
     char disk;
     int temp=x;
     int count=0;
     while(temp%2==0)
     {
         count++;
         temp=temp/2;
     }
     switch(count)
     {
        case 0:
            disk='A';
            break;
        case 1:
            disk='B';
            break;
        case 2:
            disk='C';
            break;
        case 3:
            disk='D';
            break;
        case 4:
            disk='E';
            break;
     }
    printf("Disk %c Move from Pole %d to Pole %d\n",disk,(x&(x-1))%3,(((x |(x-1)) + 1)%3));
 }
} 
int main() 
{
 int m;
 printf("\n Enter the Number of Disks : ");
 scanf("%d",&m);
 towers_hanoi(m);
 return 0; 
}
