#include <bits/stdc++.h>
using namespace std;

int main()
{
	int V = 5;
	int *parent = new int[V];
	memset(parent, -1, sizeof(int)*V);
	for(int i=0;i<V;i++)
	cout<<parent[i]<<" ";	
}	