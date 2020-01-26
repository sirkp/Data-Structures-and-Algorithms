#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
	int V;
	list<int> *adj;
	bool isCyclicUtil(int s, bool visited[], int parent);
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

bool Graph::isCyclicUtil(int s,bool visited[],int parent)
{
	if(!visited[s])
	{
		visited[s] = true;
		for(auto x: adj[s])
		if(!visited[x])
		{
			if(isCyclicUtil(x,visited,s))
			return true;	
		}	
		else if (parent!=x)
			return true;
	}
	return false;
}

bool Graph::isCyclic()// O(V+E)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	visited[i] = false;
	
	for(int i=0;i<V;i++)
	if(isCyclicUtil(i,visited,-1))
	{
		delete []visited;
		return true;
	}

	delete []visited;
	return false;	
 }

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	

	Graph g1(5); 
    g1.addEdgeUndirected(1, 0); 
    g1.addEdgeUndirected(0, 2); 
    g1.addEdgeUndirected(2, 1); 
    g1.addEdgeUndirected(0, 3); 
    g1.addEdgeUndirected(3, 4);
    
    if(g1.isCyclic())
    cout<<"contains cycle"<<endl;
    else
    cout<<"doesn't contains cycle"<<endl;
	
	Graph g2(3); 
    g2.addEdgeUndirected(0, 1); 
    g2.addEdgeUndirected(1, 2);
    if(g2.isCyclic())
    cout<<"contains cycle"<<endl;
    else
    cout<<"doesn't contains cycle"<<endl;

}