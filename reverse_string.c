
#include <stdio.h>

int main()
{
    char str1[20];
    char *s1,*s2,*s3;
    char temp;
    printf("enter value\n");
    gets(str1);
    
    
    s1=str1;
    s2=str1;
    s3=str1+1;
  
    
  
    
    while(*s3)
    {
        s2++;
        s3++;
    }
    
    
    
     while(s2>s1)
  {
        temp=*s1;
        *s1=*s2;
        *s2=temp;
        s2--;
        s1++;
      
  }
  
   
    printf("\n");
    puts(str1);
    
   


    return 0;
}

