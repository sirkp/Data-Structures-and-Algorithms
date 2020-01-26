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
	~Graph(){delete []adj;}
	void addEdgeUndirected(int u,int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void addEdgeDirected(int u, int v){adj[u].push_back(v);}

	bool isBipartite();
	void print()
	{
		for(int i=0;i<V;i++)
		{
			cout<<i<<"-->";
			for(auto x:adj[i])
			cout<<x<<"->";
			cout<<endl;	
		}
	}
};

void print_array(int arr[],int n)
{	
	cout<<"array looklike\n";
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;	
}

bool Graph::isBipartite()
{
	int *color = new int[V];
	for(int i=0;i<V;i++)
	color[i] = -1;
	
	list<int> queue;

	for(int i=0;i<V;i++)
	{
		if(color[i]==-1)
		{
			color[i] = 1;	
			queue.push_back(i);

			while(!queue.empty())
			{
				int s = queue.front();
				queue.pop_front();

				for(auto x:adj[s])
				{
					if(x == s)//self loop
					{
						print_array(color,V);
						return false;	
					}

					if(color[x]==-1)
					{
						color[x] = 1 - color[s];	
						queue.push_back(x);
					}
					else if(color[x]==color[s])
					{
						print_array(color,V);
						return false;	
					}	
				}
			}
		}
	}	
	print_array(color,V);
	delete []color;
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	Graph g(5);
	g.addEdgeUndirected(0,1);
	g.addEdgeUndirected(1,2);
	g.addEdgeUndirected(2,3);
	g.addEdgeUndirected(3,4);
	g.print();
	if(g.isBipartite())
	cout<<"Bipartite hai be\n";
	else	
	cout<<"Bipartite nahi hai!\n";
}