#include<iostream>
using namespace std;

const int V=6;          													// Number of vertices in the graph  

int min_Key(int key[], bool visited[])  									// Function to find the vertex with minimum key value 
{ 
    int min = 999, min_index;  												// 999 represents an Infinite value

    for (int v = 0; v < V; v++) 
	{ 
		cout<<"key["<<v<<"]"<<key[v]<<"  ";
        if (visited[v] == false && key[v] < min) 
		{ 
			cout<<"min: "<<min<<"\n";
            min = key[v];
			min_index = v;  
        }
    }    
    return min_index;  
}  

int print_MST(int parent[], int cost[V][V])  								// Function to print the final MST stored in parent[]  
{  
    int minCost=0;
	cout<<"Edge \tWeight\n";  
    for (int i = 1; i< V; i++) 
	{
		cout<<parent[i]<<" - "<<i<<" \t"<<cost[i][parent[i]]<<" \n";  
		minCost+=cost[i][parent[i]];
    }
	cout<<"Total cost is"<<minCost;
}  

void find_MST(int cost[V][V])  												// Function to find the MST using adjacency cost matrix representation  
{  
    int parent[V], key[V];
    bool visited[V];

    for (int i = 0; i< V; i++) 												// Initialize all the arrays 
	{ 
        key[i] = 999;    													// 999 represents an Infinite value
        visited[i] = false;
        parent[i]=-1;
    }    

    key[0] = 0;  															// Include first vertex in MST by setting its key value to 0.  
    parent[0] = -1; 														// First node is always root of MST  

    for (int x = 0; x < V - 1; x++) 										// The MST will have maximum V-1 vertices
    {  
        int u = min_Key(key, visited);  									// Finding the minimum key vertex from the set of vertices not yet included in MST  
		cout<<"u:"<<u<<"  ";
        visited[u] = true;  												// Add the minimum key vertex to the MST  
		
        for (int v = 0; v < V; v++)  										// Update key and parent arrays
        {
        	cout<<"cost["<<u<<"]"<<"["<<v<<"]: "<<cost[u][v]<<"  "<<"key[v]:"<<key[v]<<"\n";
            if (cost[u][v]!=0 && visited[v] == false && cost[u][v] < key[v])	// cost[u][v] is non zero only for adjacent vertices of u visited[v] is false for vertices not yet included in MST key[] gets updated only if cost[u][v] is smaller than key[v]  
            {  
            	
                parent[v] = u;
                cout<<"parent["<<v<<"] "<<parent[v]<<"\n";
                key[v] = cost[u][v];  
            }        
        }
    }

	print_MST(parent, cost);  												 // print the final MST  
}  

int main()  
{  
    int cost[V][V];
	cout<<"Enter the vertices for a graph with 6 vertices";
    for (int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
			cin>>cost[i][j];
        }
    }
	find_MST(cost);  

    return 0;  
}  
