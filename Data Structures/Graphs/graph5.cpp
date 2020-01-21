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
	vector<Edge> *edge;
	bool isCyclicUtil(int s, bool visited[], bool recStack[]);
public:
	
	Graph(int V,int E)
	{
		this->V = V;
		this->E = E;
		edge = new vector<Edge>;
	}

	void addEdgeUndirected(int u, int v);
	void print();
	int find(int parent[],int v);
	bool isCyclic();
	void Union(int parent[],int src,int dest);
};

void Graph::addEdgeUndirected(int u,int v)
{
	Edge temp(u,v);
	edge->push_back(temp);
}

void Graph::print()
{
	for(int i=0;i<E;i++)
	cout<<edge->at(i).getSrc()<<"->"<<edge->at(i).getDest()<<"  ";
	cout<<endl;	
}

int Graph::find(int parent[],int v)
{
	if(parent[v]==-1)
	return v;
	return find(parent,parent[v]);	
}

void Graph::Union(int parent[], int src,int dest)
{
	int xset = find(parent,src);// these
	int yset = find(parent,dest);// these
	if(xset!=yset)// these are not required as function is called from isCyclic(), but we have these as fn may be called from other fn
	parent[xset] = yset;	
}

bool Graph::isCyclic()//O(ElogV)
{
	int *parent = new int[V];
	memset(parent, -1, sizeof(int)*V);

	for(int i=0;i<E;i++)
	{
		int x = find(parent,edge->at(i).getSrc());
		int y = find(parent,edge->at(i).getDest());

		if(x==y)
		return true;
		
		Union(parent,x,y);	
	}
	return false;
}

int main()
{
	Graph g(5,5);
	g.addEdgeUndirected(0,1);
	g.addEdgeUndirected(0,2);
	g.addEdgeUndirected(1,3);
	g.addEdgeUndirected(1,4);
	g.addEdgeUndirected(3,4);
	g.print();
	if(g.isCyclic())
	cout<<"cycle hai\n";	
}