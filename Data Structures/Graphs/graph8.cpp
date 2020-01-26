/*Given a Weighted Directed Acyclic Graph and a source vertex in the graph, 
find the shortest paths from given source to all other vertices.
https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/

Given a Weighted Directed Acyclic Graph (DAG) and a source vertex s in it,
find the longest distances from s to all other vertices in the given graph.
https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/*/
#include <bits/stdc++.h>
using namespace std;
#define NINF INT_MIN
#define INF INT_MAX 

class AdjListNode
{
private:
	int v,weight;
public:
	AdjListNode(int v,int weight)
	{
		this->v = v;
		this->weight = weight;
	}
	int getV(){return v;}
	int getWeight(){return weight;}
};

class Graph
{
private:
	int V;
	list<AdjListNode> *adj;
	void topologicalSortUtil(int s,bool visited[],stack<int>& Stack);
public:
	Graph(int V)
	{
		this->V = V;
		adj = new list<AdjListNode>[V];
	}
	~Graph(){delete []adj;}
	void addEdgeDirected(int u,int v,int weight)
	{
		AdjListNode edge(v,weight);
		adj[u].push_back(edge); 
	}
	void shortestPath(int s);
	void longestPath(int s);
};

void Graph::topologicalSortUtil(int s,bool visited[], stack<int> &Stack)
{
	visited[s]=true;
	for(auto x:adj[s])
	if(!visited[x.getV()])
	topologicalSortUtil(x.getV(),visited,Stack);	
	
	Stack.push(s);
}

void Graph::shortestPath(int s)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	visited[i] = false;
	
	stack<int> Stack;
	for(int i=0;i<V;i++)
	if(!visited[i])
	topologicalSortUtil(i,visited,Stack);	
	
	int dist[V];
	for(int i=0;i<V;i++)
	dist[i] = INF;
	dist[s]=0;	

	while(!Stack.empty())
	{
		int u = Stack.top();
		Stack.pop();

		if(dist[u]!=INF)
		{
			for(auto v:adj[u])
			{
				if(dist[v.getV()]>(dist[u]+v.getWeight()))
				dist[v.getV()]  = dist[u]+v.getWeight();	
			}
		}
	}
	for(int i=0;i<V;i++)
	(dist[i]==INF)?cout<<"INF ":cout<<dist[i]<<" ";
	cout<<endl;
	delete []visited;
}
void Graph::longestPath(int s)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	visited[i]=false;
	
	stack<int> Stack;

	for(int i=0;i<V;i++)
	if(!visited[i])
	topologicalSortUtil(i,visited,Stack);

	int dist[V];
	for(int i=0;i<V;i++)
	dist[i] = NINF;
	dist[s] = 0;	
		
	while(!Stack.empty())
	{
		int u = Stack.top();
		Stack.pop();

		if(dist[u]!=NINF)
		{
			for(auto v:adj[u])
			if(dist[v.getV()]<(dist[u]+v.getWeight()))
			dist[v.getV()] = dist[u] + v.getWeight();	
		}
	}

	for(int i=0;i<V;i++)
	(dist[i]==NINF)?cout<<"NINF ":cout<<dist[i]<<" ";
	cout<<endl;
	delete []visited;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	Graph g(6); 

	g.addEdgeDirected(0, 2, 2); 
    g.addEdgeDirected(0, 5, 1); 
    g.addEdgeDirected(5, 4, 2); 
    g.addEdgeDirected(4, 1, 1); 
    g.addEdgeDirected(2, 3, 4); 
    g.addEdgeDirected(1, 3, 5);	

    // g.addEdgeDirected(0, 1, 5); 
    // g.addEdgeDirected(0, 2, 3); 
    // g.addEdgeDirected(1, 3, 6); 
    // g.addEdgeDirected(1, 2, 2); 
    // g.addEdgeDirected(2, 4, 4); 
    // g.addEdgeDirected(2, 5, 2); 
    // g.addEdgeDirected(2, 3, 7);
    // g.addEdgeDirected(3, 5, 1); 
    // g.addEdgeDirected(3, 4, -1); 
    // g.addEdgeDirected(4, 5, -2); 
  
    int s = 0;
    g.shortestPath(s); 
    g.longestPath(s);
}