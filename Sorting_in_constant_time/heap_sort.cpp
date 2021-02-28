#include<iostream>
using namespace std;

int maxH(int [],int,int);
void Build(int [],int);
void heapSort(int [],int);

int heapSize;
int count=0;
 
int main()
{
	int size,A[100];
	cout<<"Enter heap size : ";
	cin>>size;
	cout<<"Enter elements : ";
	for(int i=1;i<=size;i++)
	{
		cin>>A[i];
	}	
	int i=1;
	heapSort(A,size);
    return 0;
}

int maxH(int A[],int i,int size)
{	
	int largest,l,r;
	l=2*i;
	r=2*i+1;
	cout<<endl<<" i= "<<i<<"l= "<<l<<"r= "<<r;
	if(l<=heapSize)
	{
		count++;
		if( A[l]>A[i])
		{
			cout<<"  Compare left\n";
			largest=l;
		}
		else
		{
			cout<<"  Else\n";
			largest=i;
		}
	}
	else
		largest=i;
	
	if(r<=heapSize)
	{
		count++;
		if(A[r]>A[largest])
		{
			cout<<"  Compare right\n";
			largest=r;
		}
	}	
	if(largest!=i)
	{
		int temp=A[i];
		A[i]=A[largest];
		A[largest]=temp;
		maxH(A,largest,size);
	}
	
}

void Build(int A[],int size)
{
	heapSize=size;
	for(int i=(size/2);i>=1;i--)
	{
		maxH(A,i,size);
	}
}
 
void heapSort(int A[],int size)
{
	Build(A,size);
	for(int i=size;i>=2;i--)
	{
		int temp2=A[1];
		A[1]=A[i];
		A[i]=temp2;
		heapSize=heapSize-1;
		maxH(A,1,size);
	}
	cout<<"Sorted elements : ";
	for(int i=1;i<=size;i++)
	{
		cout<<A[i]<<"  ";
	}
	cout<<"\nTotal comparisons : "<<count;
}
