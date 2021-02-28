//Program to implement Quick sort and plot its graph.
#include<iostream>
#include<stdio.h>
using namespace std;

int count=0;
void quickSort(int [],int,int);
int partition(int [],int,int);
void swap(int *,int *);

int main()
{
	int n, arr[30];
	cout<<"How many elements : "; 
		cin>>n;
	
	cout<<"Enter elements : ";
	for(int i =0; i<n ; i++) 
		cin>>arr[i];
	
	quickSort(arr, 0, n-1);
	
	cout<<"Sorted elements : ";
	for(int i = 0; i<n; i++)
		cout<<arr[i]<<"  ";
	cout<<"\nTotal comparisons : "<<count;
	return 0;
}

void quickSort(int arr[], int p, int r)  
{  
    if (p < r)  
    {  
        int q = partition(arr, p , r);  							//q is the partiotioning index
  
        quickSort(arr, p , q - 1);  
        quickSort(arr, q + 1, r);  
    }  
}
  
int partition (int arr[], int p, int r)  
{  
    int pivot = arr[r]; 										//taking last element as pivot element 
    int i = (p - 1); 											//Index of smaller element  
  
    for (int j = p; j <= r - 1; j++)  
    {  
		count++;          
        if (arr[j] < pivot)  									//if current element is smaller than  pivot
        {  
        	//count++;
            i++; 												//increment index of smaller element  
            swap(&arr[i], &arr[j]);  
		}  
    }  
    swap(&arr[i + 1], &arr[r]);  
	return (i + 1);  
}  

void swap(int* a, int* b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  
