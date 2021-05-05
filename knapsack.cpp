#include<iostream>
#include<stdio.h>
using namespace std;

int **M,*wt,*value;
int n, sum;

int max(int, int);
int opt(int, int);
int subset_sum(int, int);

int main()
{
	cout<<"Enter no of edges: ";
	cin>>n;
	cout<<"Enter total sum: ";
	cin>>sum;
	M=new int*[n+1];
	for(int i=0;i<n+1;i++)
	{
		M[i]=new int[sum+1];
	}
	for(int i=0;i<=sum;i++)
	{
		M[0][i]=0;
	}
	wt=new int[n+1];
	value=new int[n+1];
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter weight for element "<<i<<": ";
		cin>>wt[i];
		cout<<"Enter value for element "<<i<<": ";
		cin>>value[i];
		cout<<"\n";
	}
	cout<<subset_sum(n,sum);
	return 0;
}


int max(int a, int b)
{
	return (a>b?a:b);
}

int opt(int i, int w)
{
	if(w<wt[i])
	{
		return M[i-1][w];
	}
	else
		return max(M[i-1][w], (wt[i]+M[i-1][w-wt[i]]));
}

int subset_sum(int n,int sum)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			M[i][j]=opt(i,j);
		}
	}
}
