#include<iostream>
#include<cstdlib>
using namespace std;

void quick_sort(int[],int,int);
int randomized_partition(int[],int,int);
int randomized_select(int[],int , int , int );
void swap(int *,int *);

int main()
{
	int n;
	cout<<"Enter no of elements : ";
	cin>>n;
	
	int arr[n];
	cout<<"Enter array elements : ";
	for(int i=1;i<=n;i++)
		cin>>arr[i];
		
	int p=1,r=n;

	//quick_sort(arr,p,r);
	cout<<"Sorted array : ";
	for(int i=1;i<=n;i++)
		cout<<arr[i]<<"  ";
		
	int i;
	cout<<"\nEnter i : ";
	cin>>i;

	cout<<randomized_select(arr,p,r,i);
	return 0;
}

void quick_sort(int arr[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=randomized_partition(arr,p,r);
		quick_sort(arr,p,q-1);
		quick_sort(arr,q+1,r);
	}
}

int randomized_partition (int arr[], int p, int r)  
{  
	int j=p+rand()%(r-p+1);
	swap(&arr[r],&arr[j]); 	
	
    int pivot = arr[r]; 										
    int i = (p - 1); 											//Index of smaller element  
    
    for (int j = p; j <= r - 1; j++)  
    {  
        if (arr[j] < pivot)  									//if current element is smaller than  pivot
        {  
        	i++; 												//increment index of smaller element  
            swap(&arr[i], &arr[j]);  
		}  
    }  
    swap(&arr[i + 1], &arr[r]);  
	return (i + 1);  
}  

int randomized_select(int arr[],int p, int r,int i)
{
	if (p==r)
		return arr[p];
	int q=randomized_partition(arr,p,r);
	int k=q-p+1;
	if (i == k) 													//the pivot value is the answer
		return arr[q];
	else if (i<k)
		return randomized_select(arr,p,q-1,i);
	else
		return randomized_select(arr,q+1,r,i-k);
}

void swap(int* a, int* b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}
