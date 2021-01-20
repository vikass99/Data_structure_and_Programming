/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
	
	printf("\nenter the operation you want to perform");
	printf("\n 1.   push\n 2.   pop\n 3.   display\n 4.   exit");
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
				exit(1);
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
	if (R==(n-1))
	{
		printf("\nqueue overflow");
		exit(0);
	}
	if(R==-1)
	{
	    F++;
	    R++;
	}
	
	else
	{ 
	R++;
	printf("\nenter data");
	scanf("%d",&num);
	queue[R]=num;
	}
}

void dequeue()
{
	int num;
	if (F==-1)
	{
		printf("\nunder flow");
	}
	num=queue[F];
	if(F==R)
	{
	    F=-1;
	    R=-1;
	}
	else
	{
		
		F++;
		
	}
	printf("\nvalue after deletion=%d",num);
}

void display()
{
	
	if(R==-1)
		printf("\nunderflow");
	else
	{
	
	printf("\nvalue in queue");
	while(R>=F)
	{
		printf("\t%d",queue[--R]);
	//	R--;
	}
	}
}


