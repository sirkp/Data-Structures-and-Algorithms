#include <bits/stdc++.h>
using namespace std;
int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	//IN 1D array,  the name of an array points to the 0th element of the array.

	//IN 2D array, the name of an array is a constant pointer that points to 0th 1-D array.
	//here arr is a ‘pointer to an array of 4 integers’,

	// Both the expressions (arr + i) and *(arr + i) are pointers,
	// but their base type are different. The base type of (arr + i)
	// is ‘an array of 4 units’ while the base type of *(arr + i) or arr[i] is int.

	int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int i=2,j=2;
	cout<<arr<<endl;//points to 0th 1-D array
	cout<<(*arr)<<endl<<endl;//points to 0th element of 0th 1-D array
	
	cout<<(arr+i)<<endl;//points to ith 1-D array
	cout<<*(arr+i)<<endl<<endl;//points to 0th element of ith 1-D array
	
	cout<<(*(arr+i)+j)<<endl<<endl;//points to jth element of ith 1-D array
	
	cout<<*(*(arr+i)+j)<<endl;//gives vaue of jth element of ith 1-D array
}