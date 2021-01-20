#include <stdio.h>
#include<math.h>


int flag=-1;

int main()
{
    int num,num1, total=0,i=0,l=1;
    
    scanf("%d",&num);
    
    if(num<=0)
    {
        goto Q;    
    
    }
    else if(num==1)     //1 is not a prime
    {
        flag=0;
        goto Q;
    }
    
    else if(num==2)     //2 is prime
    {
        flag=1;
        goto Q;
    }
    else
    {
    num1=num;
    while(num1)     //finding the number of digit
    {
        total++;
        num1=num1/10;
    }
    num1=num;
    while(i<total)  //check if any of digit is even then
    {               //it it is not a prime
        int x;
        i++;
        x=num1%10;
        if(x%2==0)
          {
            flag=0;
            goto Q;
          }
        num1=num1/10;
    }
    for(i=0;i<total-1;i++)
    {               //number of digit time a variable
        l=l*10;     //is multiply by 10 which is use
    }               //to find the different permutation
                    //of given number
    num1=num;
    i=0;
    while(i<total)
    {
       for(int i=2;i<=sqrt(num1);i++)   //checking number is prime or not
        {
            if(num1%i==0)
            {
                flag=0;
                goto Q;
            }
        }
       int n1,n2;
       n1=num1%10;
       n1=n1*l;                 //each time
       n2=num1/10;              //bringing the last digit to first place
       num1=n1+n2;              //and creating a new permutation of number
       i++;             
    }
    flag=1;
}
  Q:  
    if(flag==-1)            //printing output
        printf("-1");
    else if(flag==0)
        printf("0");
    else
        printf("1");
return 0;
}
