#include<iostream>
#include<list>
#include<iterator>
using namespace std;

class node
{
	public:
		int data;
		node *next;
		node(int e,node *n=0)
		{
			data=e;
			next=n;
		}		
};

class adjacency_list 
{
    public:
	 	node *head,*tail;
	    adjacency_list();
		bool empty() const										 // is list empty?
		{	
			return (head==NULL);
	    }
		int  front() 										//return front element
	    {
			return head->data;	
	    }
	    ~adjacency_list()											//destructor
	    {
	    	while (!empty()) 
				removehead();
		}
		void addtohead(int  e);
	    void addtotail(int e);
	    int removehead();
	    void display();
};

adjacency_list::adjacency_list()								//constructor
{
    head = NULL;													//initially set head and tail to null
    tail = NULL;
}	 

void adjacency_list::addtohead(int  n)
{
    node *tmp = new node (n);
    if(head == NULL)
    {
        head = tmp;													//if no element is present in list make the new element as head as well as tail
        tail = tmp;
    }
    else
    {
	    tmp->next = head;											//making head as tmp's next element  
	    head = tmp;  												//tmp is the new head
    }
}	

void adjacency_list::addtotail(int n)
{
    node *tmp = new node(n);
    if(head == NULL)												//if no element is present in list make the new element as head as well as tail
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;											//making tmp as next element of tail
        tail = tail->next;											//now tmp will be the new tail
    }
}	

int adjacency_list::removehead()								// remove front item
{ 
	int data=head->data;
	node *old = head; 											// save current head
	head = head->next; 												// skip over old head
	delete old;
	return data;														// delete the old head
}

void adjacency_list::display()
{
	if(head==NULL)
	{
		cout<<"No more elements in the list.";
		return;
	}
	cout<<"Elements in the linked list are: ";
	node *temp=head;
	while(temp )  
    {
		cout<<temp->data<<" ";  
        temp = temp->next;
        cout<<"  ";
    }
    cout<<"\n\n";
}

class graph
{
    int vertices,*v;
 	adjacency_list *adj;
 	int *v;
 	
	public:
	    graph(int vertices);							//create initial adjacency matrix
	    void inputgraph();
		void addEdge(int u, int v);						//insert a new edge
	    void BFS(int start);						//display the BFS traversal
};

graph::graph(int vertices)
{
    this->vertices = vertices;
    adj=new adjacency_list [vertices];
    adjacency_list **adj=new adjacency_list *[vertices];
    v=new int[vertices];
} 

void graph::addEdge(int u, int v)						//add an edge to the graph
{
    adj[u-1].addtotail(v);
}

void graph::inputgraph()
{
	for(int i=0;i<vertices;i++)
	{
		v[i]=i+1;
	}
	int u1,u2,edges;
	cout<<"Enter no of edges : ";
	cin>>edges;
	cout<<"Enter Edges b/w 1 and "<<vertices<<"\n";
    for(int i=0; i<edges; i++)
	{
		cin>>u1>>u2;
        addEdge(u1,u2);
    }
    
    for(int i=0;i<vertices;i++)
    {
    	cout<<i+1;
		adj[i].display();
		cout<<"\n";
	}
}

void graph::BFS(int start)
{
	bool *discovered=new bool[vertices];
	int *layer=new int[vertices];
	
	for(int i=0; i<vertices; i++)				
	{
		discovered[i] = 0;
		layer[i]=-1;
	}
	
	adjacency_list q;
	q.addtotail(start);
	layer[start-1]=0;
	int i=0;
	
	cout<<q.front()<<"\n";
	while(!q.empty())
	{
		while ((!q.empty()) && (layer[q.front()-1]==i) )
		{
			int currVertex=q.removehead();
			
			discovered[currVertex-1]=1;
			node *temp=adj[currVertex-1].head;
			while(temp!=0)
			{
				if(discovered[temp->data-1]==0)
				{
					discovered[temp->data-1]=1;
					cout<<currVertex<<"-"<<temp->data<<"\t";
					q.addtotail(temp->data);
					layer[temp->data-1]=i+1;
				}
				temp=temp->next;
			}
		}
		i++;
		cout<<"\n";
	}
}

int main()
{
	int vertices, edges;
    cout<<"Enter Number of Vertices:\n";
    cin>>vertices;
    
    graph g(vertices);
	g.inputgraph();

    int start;
    cout<<"Enter Starting Vertex:";
    cin>>start;
    g.BFS(start);
}
