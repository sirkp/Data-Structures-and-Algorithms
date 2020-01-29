//https://www.geeksforgeeks.org/assign-directions-to-edges-so-that-the-directed-graph-remains-acyclic/
#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
	int V;
	list<int> *adj;
	unordered_map<int,int> hash;
	bool isCyclicUtil(int s, bool visited[], bool recStack[]);
public:
	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}
	~Graph()
	{
		delete []adj;
	}
	void addEdgeDirected(int u,int v){adj[u].push_back(v);}
	void topologicalSort();
	void topologicalSortUtil(int s, bool visited[],stack<int>& Stack);
	void convertDirected(int x,int u);
	bool isCyclic();
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
};

void Graph::topologicalSortUtil(int s,bool visited[],stack<int>& Stack)
{
	visited[s] = true;
	for(auto x:adj[s])
	if(!visited[x])
	topologicalSortUtil(x,visited,Stack);

	Stack.push(s);	
}

void Graph::topologicalSort()
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	visited[i] = false;
	stack<int> Stack;	
	for(int i=0;i<V;i++)
	if(!visited[i])
	topologicalSortUtil(i,visited,Stack);
	
	int index = 0;
	while(!Stack.empty())
	{
		hash[Stack.top()] = index;
		Stack.pop();
		index++;
	}	
}

void Graph::convertDirected(int x,int y)
{
	if(hash[x]<hash[y])
	{
		addEdgeDirected(x,y);
		cout<<x<<" "<<y<<endl;
	}
	else
	{
		addEdgeDirected(y,x);	
		cout<<y<<" "<<x<<endl;

	}
}
bool Graph::isCyclicUtil(int s,bool visited[],bool recStack[])
{
	if(!visited[s])
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
	if(isCyclicUtil(i,visited,recStack))
	{
		delete []visited;
		delete []recStack;
		return true;
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
	Graph g(6); 
    g.addEdgeDirected(0, 1); 
    g.addEdgeDirected(0, 5); 
    g.addEdgeDirected(1, 2); 
    g.addEdgeDirected(1, 3); 
    g.addEdgeDirected(1, 4); 
    g.addEdgeDirected(2, 3);
    g.addEdgeDirected(2, 4);
    g.addEdgeDirected(3, 4);
    g.addEdgeDirected(5, 1);
    g.addEdgeDirected(5, 2);


    g.topologicalSort();
    // g.print();
    if(g.isCyclic())
    cout<<"contains cycle"<<endl;
    else
    cout<<"doesn't contains cycle"<<endl;
	cout<<endl;

    cout<<"Directed edges added"<<endl;
    g.convertDirected(0,2);
    g.convertDirected(0,3);
    g.convertDirected(4,5);
	cout<<endl;
    // g.print();
    if(g.isCyclic())
    cout<<"contains cycle"<<endl;
    else
    cout<<"doesn't contains cycle"<<endl;





}