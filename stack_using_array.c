/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int stack[100],n,top=-1;
void push();
void pop();
void display();

void main(void ) 
{
	int choice=0;
	printf("\nenter the length of stack");
	scanf("%d",&n);
	
	while(choice!=4)
	{
	
	printf("\nenter the operation you want to perform\n");
	printf("1.push  2. pop  3.display  4.exit \n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				push();
				break;
			}
		case 2:
			{
				pop();
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

void push()
{
	int num;
	if (top==(n-1))
	{
		printf("\nstack overflow");
	}
	else
	{ 
	top++;
	printf("\nenter data");
	scanf("%d",&num);
	stack[top]=num;
	}
}

void pop()
{
	int num;
	if (top==-1)
		printf("\nunder flow");
	else
	{
		num=stack[top];
		top=top-1;
		printf("\nvalue after deletion=%d",num);
	}
}

void display()
{
	int i=top;
	if(top==-1)
		printf("\nunderflow");
	else
	{
	
	printf("\nvalue in stack");
	while(i>-1)
	{
		printf("\t%d",stack[i]);
		i--;
	}
	}
}


