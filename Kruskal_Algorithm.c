#include <stdio.h>

struct graph            //declaring structure for storing detail of graph
{
    int source;
    int destination;
    int weight;
};

typedef struct graph graph;

void kruskal(graph [],int, int);        //prototype declaring
int findparent(int,int[]);

int main()                              //driver code

{
    int node, edge,i,j;
    graph temp;
    
    printf("enter the number of node\n");
    scanf("%d",&node);                      //number of node
    printf("enter the number of edge\n");
    scanf("%d",&edge);                      //number of edge
    
    graph input[edge];                      //input array which is graph type 
                                            //use to store node edge and weight
    for(i=0;i<edge;i++)
    {
        printf("enter source");
        scanf("%d",&input[i].source);
        printf("enter destination");
        scanf("%d",&input[i].destination);
        printf("enter weight");
        scanf("%d",&input[i].weight);
    }
    
    for(i=0;i<edge-1;i++)
    for(j=0;j<edge-i-1;j++)
    if(input[j].weight>input[j+1].weight)
    
    {
        temp=input[j];
        input[j]=input[j+1];                //sorting the input array in increasing order based on weight
        input[j+1]=temp;
    }
    
    kruskal(input,node,edge);
    
    return 0;
}

void kruskal(graph input[], int node, int edge)
{
    graph output[node-1];                       //output array use to store the resultant node edge weight
    int parent[node+1],count=0,i,total=0;
    
    for(int i=0;i<node+1;i++)                   //use for find and union algo
        parent[i]=i;
    
    i=0;
    
    while(count!=node-1)                
    {
        graph currentedge=input[i];
        int sourceparent=findparent(currentedge.source,parent);
        int destinationparent=findparent(currentedge.destination,parent);
        
        if(sourceparent!=destinationparent)     //if sourceparent and destinationparent are different
        {                                       //it will add in the output array and update the 
            output[count]=currentedge;          //source parent  value with destination parent value
            count++;                            //this process repeat untill resultant edge == node-1
            parent[sourceparent]=destinationparent;
            total+=currentedge.weight;
        }
    
        i++;
    }
    printf("\nsource destination weight\n");
    for(i=0;i<node-1;i++)           //printing the output
        printf("%4d %9d%9d \n",output[i].source,output[i].destination,output[i].weight);
    printf("\ntotal weight count=%d",total);
    
}

int findparent(int node, int parent[])          //it will return the parent of node
{
    if(parent[node]==node)
        return node;
    else
        return findparent(parent[node],parent);
}
