// https://www.geeksforgeeks.org/snake-ladder-problem-2/
#include <bits/stdc++.h>
using namespace std;

class VertexDistance
{
private:
	int v,distance;
public:
	VertexDistance(int v,int distance)
	{
		this->v = v;
		this->distance = distance;
	}
	int getV(){return v;}
	int getDistance(){return distance;}
};

class Graph
{
private:
	int V;
	int *snakeLadder;//taken array instead of matrix bcoz of input format given 

public:
	Graph(int V)
	{
		this->V = V;
		snakeLadder = new int[V];
	}	
	~Graph(){delete []snakeLadder;}

	void addSnakeLadder(int u,int v){snakeLadder[u]=v;}
	int getMinThrows();
};

int Graph::getMinThrows()
{
	bool *visited = new bool[V]; 
	for(int i=0;i<V;i++)
	visited[i] = false;
	
	VertexDistance s(0,0);
	visited[0] = true;
	list<VertexDistance> queue;
	queue.push_back(s);

	int tempDistance,tempV;
	while(!queue.empty())
	{
		s = queue.front();
		int v = s.getV();
		queue.pop_front();

		
		if(v == V-1)
		break;
		
		for(int i=v+1;i<=(v+6);i++)
		{
			if(!visited[i])
			{
				visited[i] = true;
				tempDistance = s.getDistance()+1;
				if(snakeLadder[i] != -1)
				tempV = snakeLadder[i];
				else
				tempV = i;
				VertexDistance temp(tempV,tempDistance);
				queue.push_back(temp);	
			}
		}	
	}

	delete []visited; 
	
	return s.getDistance();

}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		Graph g(30);
		for(int i=0;i<30;i++)
		g.addSnakeLadder(i,-1);
		
		g.addSnakeLadder(2,21);
		g.addSnakeLadder(4,7);
		g.addSnakeLadder(10,25);
		g.addSnakeLadder(19,28);

		g.addSnakeLadder(26,0);
		g.addSnakeLadder(20,8);
		g.addSnakeLadder(16,3);
		g.addSnakeLadder(18,6);

		cout<<"Min throws req- "<<g.getMinThrows()<<endl;

}		