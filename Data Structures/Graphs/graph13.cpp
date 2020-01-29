//https://www.geeksforgeeks.org/boggle-find-possible-words-board-characters/
//using backtracking
#include <bits/stdc++.h>
using namespace std;
class Graph
{
private:
	int M,N;
	char **graph;
public:
	Graph(int M, int N)
	{
		this->M = M;
		this->N = N;
		graph = new char*[M];
		for(int i=0;i<M;i++)
		graph[i] = new char[N];	
	}
	void insert(int i,int j,char c){graph[i][j]=c;}
	bool isPresent(string s);
	bool isPresentUtil(string s,int count,int i,int j,bool visited[]);
	~Graph()
	{
		delete []graph;
	}
};

bool Graph::isPresentUtil(string s,int count,int i,int j,bool visited[])
{
	if(count==s.size())
	return true;
		
	if((i+1)<M && j<N && (i+1)>=0 && j>=0 && graph[i+1][j]==s[count] && !visited[(M*(i+1))+(j)])
	{
		count++;
		visited[(i*M)+j]=true;
		bool success = isPresentUtil(s,count,i+1,j,visited);
		if(success)
		return true;
		else
		{
			count--;
			visited[(i*M)+j]=false;
		}	
	}
	if((i+1)<M && (j+1)<N && (i+1)>=0 && (j+1)>=0 && graph[i+1][(j+1)]==s[count] && !visited[(M*(i+1))+(j+1)])
	{
		count++;
		visited[(i*M)+j]=true;
		bool success = isPresentUtil(s,count,i+1,j+1,visited);
		if(success)
		return true;
		else
		{
			count--;
			visited[(i*M)+j]=false;
		}	
	}
	if((i+1)<M && (j-1)<N && (i+1)>=0 && (j-1)>=0 && graph[i+1][(j-1)]==s[count] && !visited[(M*(i+1))+(j-1)])
	{
		count++;
		visited[(i*M)+j]=true;
		bool success = isPresentUtil(s,count,i+1,j-1,visited);
		if(success)
		return true;
		else
		{
			count--;
			visited[(i*M)+j]=false;
		}	
	}


	if((i-1)<M && j<N && (i-1)>=0 && j>=0 && graph[i-1][j]==s[count] && !visited[(M*(i-1))+(j)])
	{
		count++;
		visited[(i*M)+j]=true;
		bool success = isPresentUtil(s,count,i-1,j,visited);
		if(success)
		return true;
		else
		{
			count--;
			visited[(i*M)+j]=false;
		}	
	}
	if((i-1)<M && (j+1)<N && (i-1)>=0 && (j+1)>=0 && graph[i-1][(j+1)]==s[count] && !visited[(M*(i-1))+(j+1)])
	{
		count++;
		visited[(i*M)+j]=true;
		bool success = isPresentUtil(s,count,i-1,(j+1),visited);
		if(success)
		return true;
		else
		{
			count--;
			visited[(i*M)+j]=false;
		}	
	}
	if((i-1)<M && (j-1)<N && (i-1)>=0 && (j-1)>=0 && graph[i-1][(j-1)]==s[count] && !visited[(M*(i-1))+(j-1)])
	{
		count++;
		visited[(i*M)+j]=true;
		bool success = isPresentUtil(s,count,i-1,(j-1),visited);
		if(success)
		return true;
		else
		{
			count--;
			visited[(i*M)+j]=false;
		}	
	}
	if((i)<M && (j+1)<N && (i)>=0 && (j+1)>=0 && graph[i][j+1]==s[count] && !visited[(M*(i))+(j+1)])
	{
		count++;
		visited[(i*M)+j]=true;
		bool success = isPresentUtil(s,count,i,j+1,visited);
		if(success)
		return true;
		else
		{
			count--;
			visited[(i*M)+j]=false;
		}	
	}
	if(i<M && (j-1)<N && i>=0 && (j-1)>=0 && graph[i][j-1]==s[count] && !visited[(M*(i))+(j-1)])
	{
		count++;
		visited[(i*M)+j]=true;
		bool success = isPresentUtil(s,count,i,j-1,visited);
		if(success)
		return true;
		else
		{
			count--;
			visited[(i*M)+j]=false;
		}	
	}
	return false;

}

bool Graph::isPresent(string s)
{
	int V = M*N;
	bool* visited = new bool[V];
	for(int i=0;i<V;i++)
	visited[i]=false;
	
	int	count = 0;
	for(int i=0;i<M;i++)
	for(int j=0;j<N;j++)
	{
		if(graph[i][j]==s[count])
		{
			count++;
			visited[(i*M)+j]=true;
			bool success = isPresentUtil(s,count,i,j,visited);
			if(success)
			return true;
			else
			{
				count--;
				visited[(i*M)+j]=false;	
			}
		}
	}	
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	int M=3,N=3;
	Graph g(M,N);
	char boggle[M][N] = { { 'G', 'I', 'Z' }, 
                          { 'U', 'E', 'K' }, 
                          { 'Q', 'S', 'E' } };
    for(int i=0;i<M;i++)
	for(int j=0;j<N;j++)
	g.insert(i,j,boggle[i][j]);

	for(int i=0;i<M;i++)
	{

	for(int j=0;j<N;j++)
	cout<<boggle[i][j]<<" ";
	cout<<endl;
	}
	cout<<endl;

	string s;
	cin>>s;
	if(g.isPresent(s))
	cout<<"YES\n";
	else
	cout<<"No\n";	

}