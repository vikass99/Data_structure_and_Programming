
#include <stdio.h>
#include <stdlib.h>

int queue[100],n,R=-1,F=-1;
void enqueue();
void dequeue();
void display();

void main(void ) 
{
	int choice=0;
	printf("\nenter the length of queue");
	scanf("%d",&n);
	
	while(choice!=4)
	{
	
	printf("\nenter the operation you want to perform\n");
	printf("1.enqueue  2. dequeue  3.display  4.exit \n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				enqueue();
				break;
			}
		case 2:
			{
				dequeue();
				break;
			}
		case 3:
			{
				display();
				break;
			}
		case 4:
			{
				exit(0);
				//printf("exit from code");
			}
		default:
			{
				printf("wrong choice");
			}
	}
		
	}
}

void enqueue()
{
	int num;
	printf("\nenter data");
	scanf("%d",&num);
	if (R==n-1)
	{
		printf("\nqueue overflow");
		return;
		//exit(0);
	}
	if(R==-1)
	{
	    F++;
	    R++;
	}
	
	else
	{ 
    	R++;
	}
	queue[R]=num;
	
}

void dequeue()
{
	int num;
	if (F==-1)
	{
		printf("\nunder flow");
	}
	
	else 
	
	{
	    num=queue[F];
	    if (F==R)
	    {
	        F=-1;
	        R=-1;
	    }
	    else
	    {
	    
		    F++;
	    }
	}
	printf("\nvalue after deletion=%d",num);
}

void display()
{
	int i=F;
	if(R==-1)
		printf("\nunderflow");
	else
	{
	
	printf("\nvalue in queue");
	while(i<=R)
	{
		printf("\t%d",queue[i++]);
	//	R--;
	}
	}
}



