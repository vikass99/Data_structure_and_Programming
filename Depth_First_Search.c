#include <stdio.h>
#define MAX 10

int pop();
void push(int);
int stackEmpty();               
void depthFirstSearch(int);

int stack[MAX];
int top=-1;
int visited[MAX];
int node;
int arr[MAX][MAX];


int main()
{

    int p;   
    printf("enter value either 1 or 2\t");
    scanf("%d",&p);
    while(p--)
    {
        int edge;
        if(p>=2)
        {
            printf("wrong value\nEnter value either 1 or 2");
            break;
        }
        printf("Enter the Number of nodes and edges in");
        if(0==p) printf(" First Graph:\n");
        if(1==p) printf(" Second Graph\n");
        scanf("%d %d",&node,&edge);
        int x,y;
        for(x=0;x<node;x++) for(y=0;y<node;y++) arr[x][y]=0;
        for(x=0;x<node;x++) visited[x] = 0;
        if(p==0) node = node+1;          
        printf("Enter edges between nodes\n");
 
        for(int i=0;i<edge;i++)
        {

            int to,from;
     
            printf("from");
            scanf(" %d",&from);
            printf("to");
            scanf(" %d",&to);
            arr[to][from] = 1;
            arr[from][to] = 1;
        }
        printf("\nDepthFirstSearch:\n");
        depthFirstSearch(1);
        printf("\n");
    }
    return 0;
}
void push(int val)          //push function
{
    stack[++top]=val;
}

int pop()           //pop function
{
    int ver=stack[top--];
    printf("%d\t",ver);
    return ver;
}

int stackEmpty()
{
    if(top==-1)
    return 1;
    else
    return 0;
}

void depthFirstSearch(int s)            //depthFirstSearch
{
    push(s);
    visited[s]=1;
    while(!stackEmpty())
    {
        int i;
        int v=pop();
        for(i=node-1;i>=0;i--)
        {
            if(arr[v][i]&&!(visited[i]))
            {
                push(i);
                visited[i]=1;
            }
        }
    }
}
