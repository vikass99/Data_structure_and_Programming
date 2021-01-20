
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>
void enqueue();
void dequeue();
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
	printf("\n 1.   enqueue\n 2.   dequeue\n 3.   display\n 4.   exit");
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
    node *temp;
    node *q=head;
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
        
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=temp;
    }
    temp=NULL;
    q=NULL;
}

void dequeue()
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
        node *q;
        q=head;
        head=head->next;
        printf("deleted value is%d",q->data);
        free(q);
        q=NULL;
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


