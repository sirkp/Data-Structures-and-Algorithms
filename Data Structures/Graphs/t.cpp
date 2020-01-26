//Disjoint Set (Or Union-Find) | Set 1 (Detect Cycle in an Undirected Graph)  https://www.geeksforgeeks.org/union-find/
// In this post, we will discuss the application of Disjoint Set Data Structure. The application is to check whether a given graph contains a cycle or not.
// Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not
#include <bits/stdc++.h>
using namespace std;

class Edge
{
private:
	int src,dest;
public:
	Edge(int src,int dest)
	{
		this->src = src;
		this->dest = dest;
	}
	int getSrc(){return src;}
	int getDest(){return dest;}
};

class Graph
{
private:
	int V,E;
	vector<Edge> edge;
public:
	
	Graph(int V,int E)
	{
		this->V = V;
		this->E = E;
	}
	void addEdgeUndirected(int u, int v);
};

void Graph::addEdgeUndirected(int u,int v)
{
	Edge temp(u,v);
	edge.push_back(temp);
}

int main()
{
	Graph g(5,5);
	g.addEdgeUndirected(0,1);
	g.addEdgeUndirected(0,2);
	g.addEdgeUndirected(1,3);
	g.addEdgeUndirected(1,4);
	g.addEdgeUndirected(3,4);
}