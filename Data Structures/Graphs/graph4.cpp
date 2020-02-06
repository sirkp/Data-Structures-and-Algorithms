// Detect Cycle in a Directed Graph
// https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
	int V;
	list<int> *adj;
	bool isCyclicUtil(int s, bool visited[], bool recStack[]);
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
	bool isCyclic();
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

bool Graph::isCyclicUtil(int s,bool visited[],bool recStack[])
{
	
	visited[s] = true;
	recStack[s] = true;

	for(auto x:adj[s])
	{
		if(!visited[x] && isCyclicUtil(x,visited,recStack))
		return true;
		else if(recStack[x])
		return true;	
	}
	recStack[s] = false;
	return false;
}

bool Graph::isCyclic()// O(V+E)
{
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for(int i=0;i<V;i++)
	{
		recStack[i]=false;
		visited[i]=false;		
	}

	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		if(isCyclicUtil(i,visited,recStack))
		{
			delete []visited;
			delete []recStack;
			return true;
		}		
	}
	
	delete []visited;
	delete []recStack;
	return false;	
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
    g.addEdgeDirected(2, 3); 
    
    if(g.isCyclic())
    cout<<"contains cycle"<<endl;
    else
    cout<<"doesn't contains cycle"<<endl;
	
	Graph G(4); 
    G.addEdgeDirected(0, 1); 
    G.addEdgeDirected(0, 2); 
    G.addEdgeDirected(1, 2); 
    G.addEdgeDirected(2, 0); 
    G.addEdgeDirected(2, 3); 
    G.addEdgeDirected(3, 3); 
    
    if(G.isCyclic())
    cout<<"contains cycle"<<endl;
    else
    cout<<"doesn't contains cycle"<<endl;

}