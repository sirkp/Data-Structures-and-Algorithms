#include <bits/stdc++.h>
using namespace std;
#define NINF INT_MIN 
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
	void topologicalSortUtil(int s,bool visited[],stack<int> &Stack);
public:
	Graph(int V)
	{
		this->V = V;
		adj = new list<AdjListNode>[V];
	}
	~Graph(){delete []adj;}
	void addEdgeDirectedWeighted(int u,int v,int weight);
	void longestPath(int s);
};

void Graph::addEdgeDirectedWeighted(int u, int v, int weight)
{
	AdjListNode edge(v,weight);
	adj[u].push_back(edge);
}

void Graph::topologicalSortUtil(int s,bool visited[],stack<int> &Stack)
{
	visited[s] = true;

	for(auto x:adj[s])
	if(!visited[x.getV()])
	topologicalSortUtil(x.getV(),visited,Stack);

	Stack.push(s);	
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
    g.addEdgeDirectedWeighted(0, 1, 5);  
    g.addEdgeDirectedWeighted(0, 2, 3);  
    g.addEdgeDirectedWeighted(1, 3, 6);  
    g.addEdgeDirectedWeighted(1, 2, 2);  
    g.addEdgeDirectedWeighted(2, 4, 4);  
    g.addEdgeDirectedWeighted(2, 5, 2);  
    g.addEdgeDirectedWeighted(2, 3, 7);  
    g.addEdgeDirectedWeighted(3, 5, 1);  
    g.addEdgeDirectedWeighted(3, 4, -1);  
    g.addEdgeDirectedWeighted(4, 5, -2);

    g.longestPath(1); 


}
