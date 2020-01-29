//https://www.geeksforgeeks.org/boggle-find-possible-words-board-characters/
//DFS on all vertices
#include <bits/stdc++.h>
using namespace std;

string dictionary[] = { "GEEKS", "FOR", "QUIZ", "GO" }; 
int n = sizeof(dictionary) / sizeof(dictionary[0]); 
class Graph
{
private:
	int M,N;
	char** graph;
 	void findWordsUtil(int x,int y,bool** visited, string s,unordered_map<string,bool>& hash);
 	bool isPresent(string s);
public:
	Graph(int M,int N)
	{
		this->M = M;
		this->N = N;
		graph = new char*[M];
		for(int i=0;i<M;i++)
		graph[i] = new char[N];	
 	}
	~Graph(){delete []graph;}
 	void insert(int i,int j,char c){graph[i][j]=c;}
 	void findWords();
 	void print();
};

void Graph::print()
{
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		cout<<graph[i][j]<<" ";
		cout<<endl;	
	}	
}
bool Graph::isPresent(string s)
{
	for(int i=0;i<n;i++)
	if(!s.compare(dictionary[i]))
	return true;

	return false;	
}
void Graph::findWordsUtil(int x,int y,bool** visited,string s,unordered_map<string,bool>& hash)
{

	visited[x][y] = true;
	s+=graph[x][y];
	if(isPresent(s))
	{
		if(!hash[s])
		{
			hash[s] = true;
			cout<<s<<endl;	
		}

	}
	for(int i=(x-1);i<=(x+1)&&i<M;i++)
	{
		for(int j=(y-1);j<=(y+1)&&j<N;j++)
		{
			if(i>=0&&j>=0&&!visited[i][j])
			findWordsUtil(i,j,visited,s,hash);
		}
	}	
	
	s.erase(s.length()-1);
	visited[x][y] = false;	
}

void Graph::findWords()
{
	bool **visited = new bool*[M];
	for(int i=0;i<M;i++)
	visited[i] = new bool[N];
	
	for(int i=0;i<M;i++)
	for(int j=0;j<N;j++)
	visited[i][j]=false;	

	string s = "";
	unordered_map<string,bool> hash;
	for(int i=0;i<n;i++)
	hash[dictionary[i]] = false;	

	for(int i=0;i<M;i++)
	for(int j=0;j<N;j++)
	findWordsUtil(i,j,visited,s,hash);
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
	g.findWords();
}