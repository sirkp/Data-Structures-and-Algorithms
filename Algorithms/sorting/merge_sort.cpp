#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
	int n1 = mid+1-low;
	int n2 = high-mid;

	int arr1[n1],arr2[n2];

	for(int i=0;i<n1;i++)
	{
		arr1[i] = arr[low+i];
	}
	
	for(int i=0;i<n2;i++)
	{
		arr2[i] = arr[mid+1+i];	
	}

	int i1=0,i2=0;
	int i=low;
	while(i<=high)
	{
		if(i1==n1)
		{
			arr[i]=arr2[i2];
			i2++;
		}
		else if(i2==n2)
		{
			arr[i]=arr1[i1];
			i1++;
		}
		else
		{
			if(arr1[i1]<arr2[i2])
			{
				arr[i]=arr1[i1];
				i1++;
			}
			else
			{
				arr[i]=arr2[i2];
				i2++;
			}
		}
		i++;
	}
}

void print(int arr[],int low, int high)
{
	for(int i=low;i<high;i++)
	cout<<arr[i]<<" ";
	cout<<endl;	
}

void merge_sort(int arr[],int low,int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;

		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
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

	print(arr,0,n);
	merge_sort(arr,0,n-1);
	print(arr,0,n);

}