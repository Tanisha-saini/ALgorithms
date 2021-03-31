#include<iostream>
using namespace std;

int discovered[100];

int MAX=100;
int front=-1,rear=-1;
int queuee[100];

class Queue													//Queue using arrays
{
	public:
		void push_queue(int vertex)
		{
		   if(rear == MAX-1)
		      printf("Queue Overflow\n");
		   else
		   {
		      if(front == -1)
		         front = 0;
		      rear = rear+1;
		      queuee[rear] = vertex ;
		   }
		}
		 
		int isEmpty_queue()
		{
		   if(front == -1 || front > rear)
		      return 1;
		   else
		      return 0;
		}
		 
		int pop_queue()
		{
		   int delete_item;
		   if(front == -1 || front > rear)
		   {
		      printf("Queue Underflow\n");
		      exit(1);
		   }
		   delete_item = queuee[front];
		   front = front+1;
		   return delete_item;
		}
};

class graph
{
    int vertices,edges;
 	int adj[20][20];
 	
	public:
	    graph(int vertices, int edges);							//create initial adjacency matrix
	    void addEdge(int start, int edges);						//insert a new edge
	    void BFS(int vertices,int start);						//display the BFS traversal
};

graph::graph(int vertices, int edges)
{
    this->vertices = vertices;
    this->edges = edges;
    for (int i = 0; i < vertices; i++) 							//initialize to 0
	{
		for (int j= 0; j< vertices; j++)
		{
            adj[i][j] = 0;
        }
    }
}

void graph::addEdge(int start, int edges)						//add an edge to the graph
{
    adj[start][edges] = 1;						
    adj[edges][start] = 1;
}

void graph::BFS(int vertices,int start)
{
	Queue q;
	for(int i=0; i<vertices; i++)				
	  discovered[vertices] = 0;
	
	int v=start;   
	q.push_queue(v);  
	while(!q.isEmpty_queue())
	{
		v = q.pop_queue();
		if(discovered[v])              							//if it has already been discovered by some other neighbouring vertex, it should not be printed again.
		   continue;
		   
		cout<<v<<"  ";
		discovered[v] = 1;
		
		for(int i=0; i<vertices; i++)
		{
			if(adj[v][i] == 1 && discovered[i] == 0)
			{
				q.push_queue(i);
			}
		}
	}
}

int main()
{
	int vertices, edges;
    cout<<"Enter Number of Vertices:\n";
    cin>>vertices;
    cout<<"Enter number of edges:\n";
    cin>>edges;
    
    graph g(vertices,edges);

    int source, destination;
    cout<<"Enter Edges: \n";
    for(int i=0; i<edges; i++)
	{
		cin>>source>>destination;
        g.addEdge(source,destination);
    }
    
    int start;
    cout<<"Enter Starting Vertex:";
    cin>>start;
    g.BFS(vertices,start);
}
