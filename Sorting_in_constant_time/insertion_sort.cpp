//Program to implement insertion sort counting no of comparisons 

#include<iostream>
using namespace std;

int total_comparison=0;

void insertion_sort(int arr[],int n)
{
	int key, i,j;  
    for (i = 1; i < n; i++) 
    {  
    	cout<<"\n\nFor i = "<<i;
    	key = arr[i];  
        cout<<"\nInitiallly key = "<<key<<" ";
        
		for( j=i-1;j>=0;j--)
		{
			if(arr[j]>key)
			{
				total_comparison++;
				cout<<"\nNow at  position "<<j+1<<" we have "<<arr[j];
				arr[j + 1] = arr[j];
			}    
	        else
			{
	        	total_comparison++;	
	        	break;
			}
		}
		
		arr[j + 1] = key;
		cout<<"\nAfter j loop key= "<<key<<" and at "<<j+1<<" we have "<<arr[j+1];
    } 	
}

int main()
{
	int n,arr[50];
	
	cout<<"Enter no of elements: ";
	cin>>n;
	
	cout<<"Enter elements: ";
	for(int i=0;i<n;i++)
		cin>>arr[i];

	insertion_sort(arr,n);
	
	cout<<"\n\nElements in sorted manner: ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"  ";
	}
	
	cout<<"\nTotal comparisons: "<<total_comparison;
	return 0;
}

//{
//	n
//  n-1
//	n*n-1/2
//	no of comparisons reported by user
//} 

