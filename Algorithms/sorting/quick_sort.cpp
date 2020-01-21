// Randomised quicksort
#include <bits/stdc++.h>
using namespace std;
void print_array(int arr[],int low,int high);
void my_swap(int *a,int *b)
{
	if(a!=b)
	{
		(*a) = (*a) + (*b);
		(*b) = (*a) - (*b);
		(*a) = (*a) - (*b);
	}
}

int partition(int arr[],int low,int high)
{
	srand(time(NULL));
	int random = low+(rand()%(high-low));
	my_swap(&arr[random],&arr[high-1]);

	int ii = low-1;
	int pivot = high-1;
	
	for(int i=low;i<(high-1);i++)
	{
		if(arr[i]<arr[pivot])
		{
			ii++;
			my_swap(&arr[i],&arr[ii]);
		}
	}

	ii++;
	my_swap(&arr[pivot],&arr[ii]);

	return ii;
}

void quicksort(int arr[],int low,int high)
{	
	if(low<high)
	{
		int p = partition(arr,low,high);
		cout<<low<<" "<<high<<" -> "<<p<<"--> ";
		print_array(arr,0,5);
		quicksort(arr,low,p);
		quicksort(arr,p+1,high);
	}	
}

void print_array(int arr[],int low,int high)
{
	for(int i=low;i<high;i++)
	cout<<arr[i]<<" ";
	cout<<endl;	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];

	print_array(arr,0,n);	
	
	quicksort(arr,0,n);

	print_array(arr,0,n);	
}