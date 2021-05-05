#include<iostream>
using namespace std;

class edge
{
	public:
		int source;
		int destination;
		int weight;
};

edge *E;
int v,e;			//no of vertices no of edges

class node
{
	public:
		int data;
		node *next;
		node()
		{
			next=NULL;
		}
};

class list
{
	public:
		node *head;
		node *tail;
		
		list()
		{
			head=tail=0;
		}
};

node *verticeslist;
list *comp;

void input()
{
	cout<<"Enter no of vertices: ";
	cin>>v;
	cout<<"Enter no of edges: ";
	cin>>e;
	
	verticeslist=new node[v+1];
	for(int i=1;i<=v;i++)
	{
		verticeslist[i].data=i;
	}
	
	E=new edge[e+1];
	cout<<"Enter edges in format of source destination weight:";
	for(int i=1;i<=e;i++)
	{
		cin>>E[i].source>>E[i].destination>>E[i].weight;
	}
}

void create_comp()
{
	comp=new list[v+1];
	for(int i=1;i<=v;i++)
	{
		comp[i].head=comp[i].tail=&verticeslist[i];
	}
}

void sort();

void kruskel()
{
	node *h2;
	create_comp();
	sort();
	for(int i=1;i<=e;i++)
	{
		if(comp[E[i].source].head  !=   comp[E[i].destination].head  &&  comp[E[i].source].tail  !=   comp[E[i].destination].tail)
		{
			h2=comp[E[i].destination].head;
			comp[E[i].source].tail->next=h2;
			comp[E[i].source].tail=comp[E[i].destination].tail;
		}
		while(h2!=NULL)
		{
			comp[h2->data]=comp[E[i].source];
			h2=h2->next;
			cout<<"("<<E[i].source<<","<<E[i].destination<<")\t";
		}
		
	}
}

void sort()
{
	int j;
	edge temp;
	for(int i=2;i<=e;i++)
	{
		j=i-1;
		temp=E[i];
		while(j>0 && E[j].weight>temp.weight)
		{
			E[j+1].source=E[j].source;
			E[j+1].destination=E[j].destination;
			E[j+1].weight=E[j].weight;
			j--;
		}
		E[j+1]=temp;
	}
}

int main()
{
	input();
	kruskel();
	return 0;
}
