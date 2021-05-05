//DEPTH FIRST SEARCH
#include<iostream>
using namespace std;
 
class node
{
    public: 
	node *next;
    int vertex;
   
};
 
node *G[20];   
int visited[20];
int n;
void insert(int vi,int vj)
{
    node *p,*q;
    
	q=new node();
    q->vertex=vj;
    q->next=NULL;
     
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
		p=G[vi];
		while(p->next!=NULL)
        	p=p->next;
        p->next=q;
    }
}

void DFS(int i)
{
    node *p;
	cout<<i;
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->vertex;
       
	   if(!visited[i])
            DFS(i);
        p=p->next;
    }
}
 
void read_graph()
{
    int i,vi,vj,no_of_edges;
    cout<<"Enter number of vertices:";  
    cin>>n;
   
	for(i=0;i<n;i++)
    {
        G[i]=NULL;
       
		cout<<"Enter number of edges:";
       	cin>>no_of_edges;
 
       	for(i=0;i<no_of_edges;i++)
        {
        	cin>>vi;
			cin>>vj;
			insert(vi,vj);
        }
    }
}
 

 
int main()
{
    int i;
    read_graph();
       
	for(i=0;i<n;i++)
        visited[i]=0;
	
	int start;
	cout<<"enter starting vertex : ";
	cin>>start; 
    DFS(start);
}

