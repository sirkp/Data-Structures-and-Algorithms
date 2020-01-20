#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100
int linear_search(int arr[],int& n, int key);
void print_array(string s,int arr[],int& n);

void delete_element(int arr[], int& n, int key)
{
	int pos = linear_search(arr,n,key);
	if(pos>=0)
	{
		for(int i=pos+1;i<n;i++)
		arr[i-1]=arr[i];
		
		n--;
	}
	else
	{
		cout<<"element hai hi nahi\n";
	}
	print_array("array after deleton",arr,n);	

}

void insert_element(int arr[],int& n, int key, int pos)
{
	if(pos>n)//can be inserted in the sequence or at the end of sequence only
	return;
	else
	{
		if(pos==n)
		arr[pos]=key;
		else
		{
			for(int i=(n-1);i>=pos;i--)
			arr[i+1]=arr[i];
			
			arr[pos] = key;
		}

		n++;	
	}	
}

void append_element(int arr[], int& n,int key)
{
	insert_element(arr,n,key,n);
}

int linear_search(int arr[],int& n, int key)
{
	for(int i=0;i<n;i++)
	if(arr[i]==key)
	return i;

	return -1;	
}

void print_array(string s,int arr[],int& n)
{
	cout<<s<<endl;

	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;

}

int main()
{

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif	

	int n;
	cin>>n;
	if(n>MAX_SIZE)//given array size is bigger than allowed size
	return 0;	

	int arr[MAX_SIZE];

	for(int i=0;i<n;i++)
	cin>>arr[i];

	print_array("Given input array",arr,n);


	//INSERTION-O(n)
	int key,pos;
	cin>>key>>pos;

	insert_element(arr,n,key,pos);
	print_array("array after insertion",arr,n);


	//LINEAR SEARCH-O(n)
	int to_be_searched;
	cin>>to_be_searched;

	int index = linear_search(arr, n, to_be_searched);
	
	if(index>=0)
	cout<<"position- "<<index+1<<endl;
	else
	cout<<"Nhi hai\n";	

	//DELETION-O(n)
	int to_be_deleted;
	cin>>to_be_deleted;

	delete_element(arr,n,to_be_deleted);

	//APPEND
	int to_be_appended;
	cin>>to_be_appended;

	append_element(arr,n,to_be_appended);

	print_array("After appending",arr,n);




	



}