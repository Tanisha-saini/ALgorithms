//program to implement bucket sort. 
#include<iostream>
using namespace std;

class Node 
{
	public:
		double data;
		Node *next;
};

void BucketSort(double arr[],int size,int bsize);
class Node *InsertionSort(class Node *list);
int getBucketIndex(double value);

void BucketSort(double arr[],int size,int bsize) 
{
	int i, j;
	Node* buckets[bsize];
	
	for (i = 0; i < bsize; i++)							  			// Initialize empty buckets
	{
		buckets[i] = NULL;
	}
	
	for (i = 0; i < size; i++)										// Fill the buckets with respective elements
	{
		Node *current;
		int pos = getBucketIndex(arr[i]);
		current = new Node;
		current->data = arr[i];
		current->next = buckets[pos];
		buckets[pos] = current;
	}
	
	for (i = 0; i < bsize; i++)										// Print the buckets along with their elements 
	{
		cout << "Bucket[" << i << "] : ";
		Node*cur=buckets[i];
		while(cur)
		{
			cout<<"  "<<cur->data<<" ";
			cur=cur->next;
		}
		cout << endl;
	}
	
	for (i = 0; i < bsize; i++)                          			// Sort the elements of each bucket 
	{
		buckets[i] = InsertionSort(buckets[i]);
	}
	
	cout << "-------------" << endl;
	cout << "Bucktets after sorted" << endl;
	for (i = 0; i < bsize; i++) 
	{
		cout << "Bucket[" << i << "] : ";
		Node*cur=buckets[i];
		while(cur)
		{
			cout<<"  "<<cur->data<<" ";
			cur=cur->next;
		}
		cout << endl;
	}
	
	for (j = 0, i = 0; i <bsize; i++)                       		//Put sorted elements in arr
	{
		Node *node;
		node = buckets[i];
		while (node) 
		{
		  arr[j++] = node->data;
		  node = node->next;
		}
	}
	
	for (i = 0; i < bsize; i++)
	{
		Node *node;
		node = buckets[i];
		while (node)
		{
			Node *tmp;
			tmp = node;
			node = node->next;
			delete tmp;
		}
	}
	
	for (i = 0; i < size; i++)                             			//printing
	{
		cout<< arr[i]<<" ";
	}
	cout << endl;	
}

class Node *InsertionSort( Node *list) 								// Function to sort the elements of each bucket
{
	Node *k, *nodeList;
	if (list == 0 || list->next == 0) 
	{
		return list;
	}
	
	nodeList = list;
	k = list->next;
	nodeList->next = 0;
	while (k != 0)
	{
		Node *ptr;
		if (nodeList->data > k->data)
		{
			Node *tmp;
			tmp = k;
			k = k->next;
			tmp->next = nodeList;
			nodeList = tmp;
			continue;
		}
		
		for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) 
		{
		  if (ptr->next->data > k->data)
		    break;
		}
		
		if (ptr->next != 0)
		{
			Node *tmp;
			tmp = k;
			k = k->next;
			tmp->next = ptr->next;
			ptr->next = tmp;
			continue;
		} 
		else
		{
			ptr->next = k;
			k = k->next;
			ptr->next->next = 0;
			continue;
		}
	}
	return nodeList;
}

int getBucketIndex(double value) 								
{
  return (int(value/10));											// 10 is the interval such that 0-9 falls in 1 bucket , 10-19 in second and so on 
}

int main() 
{
	int size;
	cout<<"Enter the size of the array : ";
	cin>>size;
	double arr[size];
	cout<<"Enter the elements of the array : ";
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	
	int bsize;
	cout<<"Enter the number of buckets : ";
	cin>>bsize;
	
	BucketSort(arr,size,bsize);
	return 0;
}
