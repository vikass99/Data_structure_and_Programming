#include <stdio.h> //for input output function
#include<stdlib.h> //using for exit()

void push();
void pop();
void display();

int queue1[100], queue2[100], rear1=-1,rear2=-1, front1=-1, front2=-1,n;

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
void push()   //push operation which perform entering of data into stack 
{              //but here we have to perform using queue
    if(rear1==n-1)
    {
        printf("overflow\n"); //overflow when queue is full
    }
                                                                                    
    else if(rear1==-1&&front1==-1) //first time entry                               
    {
    front1++;
    rear1++;
    printf("enter data\n");
    scanf("%d",&queue1[rear1]);
    }
    else                        //entry when queue have already data present
    {
        rear1++;
        printf("enter data\n");
        scanf("%d",&queue1[rear1]);
    }
}

void pop() //pop operation to perform from stack
{
    if(front1==-1&&front2==-1)
    {
        printf("under flow\n"); //underflow when no data is present
    }
    else
    {
        front2++;
        while(front1!=rear1)
        {
            queue2[++rear2]=queue1[front1++];
        }
        printf("deleted value are %d",queue1[rear1]); //delete value one by one
        rear1=-1;
        front1=0;
        while(front2<=rear2)
        {
            queue1[++rear1]=queue2[front2++];//again storing the value back to queue1
        }
        front2=-1;
        rear2=-1;
        
        if(rear1==-1)           //if deleted value was last element
        {
            front1=-1;
        }
    }
}

void display()
{
    int i=rear1;
    if (front1==-1) 
        printf("under flow\n");
    else
    {
        while(i>=front1)
        {
        printf("%d  ",queue1[i]);
        i--;
        }
    }
    
}


