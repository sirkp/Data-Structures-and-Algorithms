// Topological sorting for Directed Acyclic Graph
//https://www.geeksforgeeks.org/topological-sorting/
#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
	int V;
	list<int> *adj;
public:
	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}
	void addEdgeDirected(int u, int v)
	{
		adj[u].push_back(v);
	}
	void print()
	{
		for(int i=0;i<V;i++)
		{
			cout<<i<<"-->";
			for (auto x:adj[i])
			{
				cout<<x<<"->";
			}
			cout<<endl;
		}
	}

	void topologicalSort();
	void topologicalSortingUtil(int s, bool visited[],stack<int> &stack);
};

void Graph::topologicalSortingUtil(int s,bool visited[],stack<int> &Stack)
{
	visited[s]=true;
	for(auto x:adj[s])
	if(!visited[x])
	topologicalSortingUtil(x,visited,Stack);

	Stack.push(s);
}

void Graph::topologicalSort()
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	visited[i]=false;
	
	stack<int> Stack;

	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		topologicalSortingUtil(i,visited,Stack);	
	}	
	while(!Stack.empty())
	{
		cout<<Stack.top()<<" ";
		Stack.pop();
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	Graph g(6); 
    g.addEdgeDirected(5, 2); 
    g.addEdgeDirected(5, 0); 
    g.addEdgeDirected(4, 0); 
    g.addEdgeDirected(4, 1); 
    g.addEdgeDirected(2, 3); 
    g.addEdgeDirected(3, 1);

    g.topologicalSort();
}