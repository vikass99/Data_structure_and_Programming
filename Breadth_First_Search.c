#include <stdio.h>
#include <stdlib.h>

struct queue 
{
  int items[40];
  int front;
  int rear;
};

struct queue* create_queue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int is_empty(struct queue* q);

struct node 
{
  int vertex;
  struct node* next;
};

struct node* create_node(int);

struct Graph 
{
  int numVertices;
  struct node** adjlists;
  int* visited;
};

                                                                        // BFS algorithm
void breadthFirstSearch(struct Graph* graph, int startvertex)
{
  struct queue* q = create_queue();

  graph->visited[startvertex] = 1;
  enqueue(q, startvertex);

  while (!is_empty(q))
  {
                                        //  printQueue(q);
      int current = dequeue(q);
      printf(" %d ", current);

      struct node* temp = graph->adjlists[current];

      while (temp)
      {
      int adjvertex = temp->vertex;

      if (0==graph->visited[adjvertex])
      {
        graph->visited[adjvertex] = 1;
        enqueue(q, adjvertex);
      }
      temp = temp->next;
      }
  }
}

                                                                     // Creating a node
struct node* create_node(int v)
{
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

                                                                     // Creating a graph
struct Graph* create_graph(int vertices)
{
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjlists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++)
  {
    graph->adjlists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}

                                                                    // Add edge
void add_edge(struct Graph* graph, int src, int dest)
{
                                                                    // Add edge from src to dest
  struct node* newNode = create_node(dest);
  newNode->next = graph->adjlists[src];
  graph->adjlists[src] = newNode;

                                                                    // Add edge from dest to src
  newNode = create_node(src);
  newNode->next = graph->adjlists[dest];
  graph->adjlists[dest] = newNode;
}

                                                                    // Create a queue
struct queue* create_queue()
{
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

                                                                    // Check if the queue is empty
int is_empty(struct queue* q)
{
  if (-1==q->rear)
    return 1;
  else
    return 0;
}

                                                                // Adding elements into queue
void enqueue(struct queue* q, int value)
{
  if (39==q->rear)
    printf("\nQueue is Full!!");
  else
  {
    if (-1==q->front)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

                                                                // Removing elements from queue
int dequeue(struct queue* q)
{
  int item;
  if (is_empty(q))
  {
    printf("Queue is empty");
    item=-1;
  } 
  else
  {
    item = q->items[q->front];
    q->front++;
    if (q->front>q->rear)
    {
      
      q->front = q->rear=-1;
    }
  }
  return item;
}

int main()
{
  struct Graph* graph1 = create_graph(5);
  struct Graph* graph2 = create_graph(6);
  add_edge(graph1, 0,1);
  add_edge(graph1, 0,2);
  add_edge(graph1, 0,3);
  add_edge(graph1, 1,2);
  add_edge(graph1, 2,4);
  
  add_edge(graph2, 1,4);
  add_edge(graph2, 1,2);
  add_edge(graph2, 2,3);
  add_edge(graph2, 2,5);
  add_edge(graph2, 5,6);

  printf("\nBREADTHFIRSTSEARCH FOR FIRST GRAPH\n");
  breadthFirstSearch(graph1, 0);
  
  printf("\nBREADTHFIRSTSEARCH FOR SECOND GRAPH\n");
  breadthFirstSearch(graph2, 1);
  return 0;
}

