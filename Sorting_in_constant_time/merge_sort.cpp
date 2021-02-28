//Program to implement merge sort and count no of comparisons.

#include<iostream>
using namespace std;

void mergesort(int *,int,int);						//function to split arrays into two parts
void merge(int *,int,int,int);						//merge the two arrays
int count=0;

int main()
{
	int n;
	cout<<"\nEnter number of elements : ";
	cin>>n;
 	
	int arr[n];
	
	cout<<"Enter elements : ";
	for(int i = 0; i < n; i++)
		cin>>arr[i];
 
 	mergesort(arr, 0, n-1);
	cout<<"Total comparisons: "<<count;
 
	cout<<"\nSorted Elements : ";
	for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
 	//cout<<""
	return 0;
}

void mergesort(int *a, int p, int q)
{
	int r;												//middle element
	if (p < q)											//divide array into two parts till p < q
	{
		r=(p+q)/2;										//finding mid element
		
		mergesort(a, p, r);								//split array into two halves p....q and q+1.....r
		mergesort(a, r+1, q);
		merge(a, p , q, r);								//merge the two arrays into one 
	}
}

void merge(int *arr, int p , int q, int r)
{
	int i, j, k, temp[q-p+1];
	i = p;												//starting index for 1st array 
	k = 0;												//index for temp array
	j = r + 1;											//starting index for 2nd array 
 	
 	for(int l=i;l<=r;l++)
 		cout<<arr[l]<<" ";
 	cout<<"\n";
	while (i <= r && j <= q)							//merge the two arrays in final array
	{
		count++;
		if (arr[i] < arr[j])
		{
			temp[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = arr[j];
			k++;
			j++;
		}
		
	}
	
 	while (i <= r)										//inserting remaining values of 1st subarray
	{
		temp[k] = arr[i];
		k++;
		i++;
	}

	while (j <= q)										//inserting remaining values of 2nd subarray
	{
		temp[k] = arr[j];
		k++;
		j++;
	}
 
	for (i = p; i <= q; i++)							//copying temp back to original arr
	{
		arr[i] = temp[i-p];
	}
}
