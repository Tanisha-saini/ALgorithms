#include <iostream>
using namespace std;

void radix_sort(int [], int);
void counting_sort(int [],int,int);

int main() 
{
	int array[50],n;
	
	cout<<"Enter number of elements : ";
	cin>>n;
	cout<<"Enter elements : ";
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	radix_sort(array, n);
	
	return 0;
}

void radix_sort(int array[], int n)
{
	int max = array[0];
	for (int i = 1; i < n ; i++)
	{
		if (array[i] > max)
  			max = array[i];
	}
	
	for (int place = 1; max / place > 0; place *= 10)
		counting_sort(array, n, place);
	
	cout<<"\nSorted elements : ";
	for (int i = 0; i < n; i++)
		cout << array[i] <<"  ";
}

void counting_sort(int array[], int n, int place) 
{
	const int max = 10;
	int output[n];
	int count[max];
	
	for (int i = 0; i < max; ++i)
		count[i] = 0;
	
	for (int i = 0; i < n; i++)
		count[(array[i] / place) % 10]++;
	
	for (int i = 1; i < max; i++)
		count[i] += count[i - 1];
	
	for (int i = n - 1; i >= 0; i--) 
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	
	for (int i = 0; i < n; i++)
		array[i] = output[i];
}
