//A simple representation of graph using STL
//https://www.geeksforgeeks.org/graph-and-its-representations/
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void print(vector<int> adj[], int V)
{
	for(int i=0;i<V;i++)
	{	cout<<i<<"-->";
		for(auto x:adj[i])
		cout<<x<<"->";
		cout<<endl;	
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int V = 5;
	
	vector<int> adj[V];
	addEdge(adj,0,1);	
	addEdge(adj,0,4);	
	addEdge(adj,1,2);	
	addEdge(adj,1,3);	
	addEdge(adj,1,4);	
	addEdge(adj,2,3);	
	addEdge(adj,3,4);	
	print(adj,V);
}