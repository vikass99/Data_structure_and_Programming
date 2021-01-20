#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>

void createnode();
void display();
void josephus();

struct node
{
    int data;               //declearing structure
    struct node *next;
};

typedef struct node node;
node *head=NULL;


int main()
{
   int i,n;
   printf("enter the number of node in linklist\t");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       createnode();            //create node will create the 
   }                            //circular linklist.
   display();                   //display() will display the circular linklist
   josephus();
   
    return 0;
}

void createnode()               //creating circular link 
{
    node *temp;
    temp=(node*) malloc(sizeof(node));
    if (temp==NULL)
    {
        printf("memory is full");
        exit;
    }
    
    printf("enter the data\n");
    scanf("%d",&temp->data);
    
    if (head==NULL)
    {
        head=temp;
        temp->next=head;
    }
    else
    {
        node *q=head;
        while(q->next!=head)
        {
            q=q->next;
        }
        q->next=temp;
        temp->next=head;
        temp=NULL;
        q=NULL;
    }
}

void display()          //printing the circular
{                       //linklist
    node *q=head;
    while(q->next!=head)
    {
        printf("%d->",q->data);
        q=q->next;
    }
    printf("%d",q->data);
}

void josephus()             //josephus()
{                           //it will remove the 
    int c=1;                //3rd node in every 
    node *p=head;           //count.And at last 
    node *q=NULL;           //only single node will
    while(p->next!=p)       // servive which point 
    {                       //to it self.
        while(c!=3)
        {
            q=p;
            c++;
            p=p->next;
        }
        p=p->next;
        q->next=p;
        c=1;
    }
    printf("\n\nthe node which survive at last is %d ",p->data);   //printing the single node
}


