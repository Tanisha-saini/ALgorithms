#include<iostream>
using namespace std;
void count_sort(int [] , int , int);

int main()
{
	int n,key;
	cout<<"Enter size of array : ";
	cin>>n;
	cout<<"Enter keys of array : ";
	cin>>key;
	
	int *arr=new int[key];
	cout<<"\nEnter array : ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	count_sort(arr,n,key);
	return 0;
}

void count_sort(int arr[],int n,int k)
{
	int *b=new int[n];
	int *c=new int[k+1];
	
	for(int i=0;i<k+1;i++)
		c[i]=0;
	
	for(int i=0;i<n;i++)
		c[arr[i]]++;
	
	for(int i=1;i<=k;i++)
		c[i]+=c[i-1];
		
	for(int i=n-1;i>=0;i--)
	{
		c[arr[i]]=c[arr[i]]-1;
		b[c[arr[i]]]=arr[i];
	}
	
	for(int i=0;i<n;i++)
		arr[i]=b[i];
	
	cout<<"\nSorted array is : ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"  ";
}
