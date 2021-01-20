/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void push();
void pop();
void display();

struct node 
{
    int data;
    struct node *next;
};
typedef struct node node;

node *head=NULL;

void main(void)
{
   int choice=0;
   while(choice!=4)
	{
	
	printf("\nenter the operation you want to perform");
	printf("\n 1.   push\n 2.   pop\n 3.   display\n 4.   exit");
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
    node *temp;
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
    printf("\nmemory is full");
    return;
    }
    printf("\nenter data");
    scanf("%d",&temp->data);
    
    if(head==NULL)
        head=temp;
    else
    {
        temp->next=head;
        head=temp;
        temp=NULL;
    }
}

void pop()
{
    if(head==NULL)
    {
        printf("\nunder flow");
    }
    else if(head->next==NULL)
    {
        printf("deleted value is%d",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        node *q,*p;
        q=head;
        while(q->next!=NULL)
        {
            p=q;
            q=q->next;
        }
        printf("deleted value is%d",q->data);
        p->next=NULL;
        free(q);
        q=NULL;
        p=NULL;
    }
}

void display()
{
    node *q;
    q=head;
    while(q)
    {
        printf("\t%d",q->data);
        q=q->next;
    }
}


