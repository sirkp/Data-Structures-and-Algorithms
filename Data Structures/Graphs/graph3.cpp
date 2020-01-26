#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
	int V;
	list<int> *adj;
	void DFSUtil(int s, bool visited[]);
public:
	
	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}
	~Graph(){delete []adj;}
	void addEdgeDirected(int u, int v);
	void addEdgeUndirected(int u, int v);
	void print();
	void DFS(int s);
	void DFSAll();
};

void Graph::addEdgeDirected(int u,int v)
{
	adj[u].push_back(v);
}

void Graph::addEdgeUndirected(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::print()
{
	for(int i=0;i<V;i++)
	{
		cout<<i<<"-->";
		for(auto x:adj[i])
		cout<<x<<"->";
		cout<<endl;
	}
}

void Graph::DFSUtil(int s,bool visited[])
{
	visited[s] = true;
	cout<<s<<" ";
	for(auto x:adj[s])
	if(!visited[x])
	DFSUtil(x,visited);
}

void Graph::DFSAll()
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	visited[i]=false;	

	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		DFSUtil(i,visited);	
	}
	cout<<endl;
	delete []visited;
}

void Graph::DFS(int s)// O(V+E)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	visited[i]=false;		

	DFSUtil(s,visited);
	cout<<endl;
	delete []visited;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	Graph g(4); 
    g.addEdgeDirected(0, 1); 
    g.addEdgeDirected(0, 2); 
    g.addEdgeDirected(1, 2); 
    g.addEdgeDirected(2, 0); 
    g.addEdgeDirected(2, 3); 
    g.addEdgeDirected(3, 3); 

    g.DFS(2);
    g.DFSAll();

    Graph G(6);
	G.addEdgeUndirected(0,1);
	G.addEdgeUndirected(0,2);
	G.addEdgeUndirected(1,3);
	G.addEdgeUndirected(2,4);
	G.addEdgeUndirected(1,4);
	G.addEdgeUndirected(3,4);
	G.addEdgeUndirected(3,5);
	G.addEdgeUndirected(4,5);
	G.DFS(4);
	G.DFSAll();
}