#include <stdio.h>

void breadthFirstSearch(int);

 static int graph[5][5];
 static int visited[5];
 int queue[5],rear=-1,front=-1;
 
int main()
{
    
    int i,j,to,from,edge,start;
   
    printf("enter number of edge");
    scanf("%d",&edge);
    
    for(i=0;i<edge;i++)
    {
        printf("enter from");
        scanf("%d",&from);
        printf("enter to");
        scanf("%d",&to);
        
        graph[to][from]=1;
        graph[from][to]=1;
    }
   
   printf("Enter start vertex  ");
   scanf("%d",&start);
   
   printf("MARTIX REPRESENTATION OF GRAPH\n");
   for(i=0;i<5;i++)
   {
       for(j=0;j<5;j++)
       {
           printf("%d  ",graph[i][j]);
       }
       printf("\n");
   }
   
   printf("breadthFirstSearch\n");
    breadthFirstSearch(start);
    return 0;
       
}

void breadthFirstSearch(int i)
{
    visited[i]=1;
    
    rear++;
    front++;
    queue[rear]=i;
    
    while(front<=rear)
    {
        for(int j=0;j<5;j++)    
        {
            if(1==graph[i][j] && 0==visited[j])
            {
                visited[j]=1;
                queue[++rear]=j;
            }
        }
        printf("%d  ",queue[front++]);
        i=queue[front];
    }
}
