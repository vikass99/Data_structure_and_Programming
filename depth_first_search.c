
#include <stdio.h>

void DepthFirstSearch(int);

 static int graph[5][5];
 static int visited[5];

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
   
   for(i=0;i<5;i++)
   {
       for(j=0;j<5;j++)
       {
           printf("%d ",graph[i][j]);
       }
       printf("\n");
   }
   
   printf("\n");
   printf("DepthFirstSearch\n");
   
    DepthFirstSearch(start);
    return 0;
       
}

void DepthFirstSearch(int i)
{
    int j;
	printf("%d ",i);
    visited[i]=1;
	
	for(j=0;j<5;j++)
       if(!visited[j]&&graph[i][j]==1)
            DepthFirstSearch(j);
}


