#include<bits/stdc++.h> 
using namespace std;
int main() 
{ 
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	

	int l;
	cin>>n>>q;
	int arr[2][n]={0};

	int lock1 = 0;
	int lock2 = 0;

	while(q--)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;

		if(arr[x][y]==1)
		arr[x][y]=0;
		else	
		arr[x][y]=1;


	}
} 