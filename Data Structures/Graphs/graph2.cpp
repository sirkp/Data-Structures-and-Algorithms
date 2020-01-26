// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
// BFS
#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
	int V;
	list<int> *adj;//pointer to adjacency list
public:
	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}
	~Graph(){delete []adj;}
	void addEdgeDirected(int u,int v);
	void addEdgeUndirected(int u,int v);
	void BFS(int s);
	void BFSAll();
	void print();
};

void Graph::print()
{
	for(int i=0;i<V;i++)
	{
		cout<<i<<"-->";
		for(auto x: adj[i])
		cout<<x<<"->";
		cout<<endl;
	}
}

void Graph::addEdgeDirected(int u,int v)
{
	adj[u].push_back(v);
}

void Graph::addEdgeUndirected(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::BFS(int s)//O(V+E)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	visited[i] = false;
	
	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	list<int>::iterator i;

	while(!queue.empty())//O(V)
	{
		s = queue.front();
		cout<<s<<" ";
		queue.pop_front();
		for(i = adj[s].begin();i!=adj[s].end();i++)//total O(E)
		{
			if(!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	cout<<endl;
	delete []visited;
}

void Graph::BFSAll()// Modified BFS to print all vertices
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	visited[i]=false;
	
	list<int> queue;
	for(int s=0;s<V;s++)
	{
		if(!visited[s])
		{
			visited[s]=true;
			queue.push_back(s);

			while(!queue.empty())
			{
				s = queue.front();
				cout<<s<<" ";
				queue.pop_front();

				for(auto x:adj[s])
				if(!visited[x])
				{
					visited[x]=true;
					queue.push_back(x);
				}	
			}
		}
	}
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
	g.addEdgeDirected(0,1);
	g.addEdgeDirected(0,2);
	g.addEdgeDirected(1,2);
	g.addEdgeDirected(2,0);
	g.addEdgeDirected(2,3);
	g.addEdgeDirected(3,3);

	g.BFS(2);
	g.BFSAll();


	Graph G(6);
	G.addEdgeUndirected(0,1);
	G.addEdgeUndirected(0,2);
	G.addEdgeUndirected(1,3);
	G.addEdgeUndirected(2,4);
	G.addEdgeUndirected(1,4);
	G.addEdgeUndirected(3,4);
	G.addEdgeUndirected(3,5);
	G.addEdgeUndirected(4,5);
	G.BFS(4);
	G.BFSAll();
	// g.print();
}