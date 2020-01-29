// https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> amount)
{
	for(auto x:amount)
	cout<<x<<" ";
	cout<<endl;	
}

void minCashFlow(int *graph,int N)
{
	vector<int> amount(N);
	for(int i =0;i<N;i++)
	amount[i] = 0;
		
	for(int i =0;i<N;i++)
	for(int j=0;j<N;j++)
	amount[j] += *(graph+(N*i)+j) - *(graph+(N*j)+i);

	for(auto itr = amount.begin();itr!=amount.end();itr++)
	{
		if(*itr==0)
		amount.erase(itr);	
	}

	int count = 0;
	while((int)amount.size()>0)
	{
		auto itrMax = max_element(amount.begin(),amount.end());
		auto itrMin = min_element(amount.begin(),amount.end());
		if(abs(*(itrMin))> *(itrMax))
		{
			*(itrMin) += *(itrMax);
			amount.erase(itrMax); 
		}
		else if(abs(*(itrMin))< *(itrMax))
		{
			*(itrMax) += *(itrMin);
			amount.erase(itrMin);
		}
		else
		{
			int temp = (*itrMax);
			amount.erase(itrMin);
			amount.erase(find(amount.begin(),amount.end(),temp));
		}
		count++;
	}
	cout<<count<<endl;
		
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int N = 4;
	int graph[N][N] = {
						{0,20,0,20},
						{0,0,25,0},
						{30,0,0,0},
						{0,15,10,0},
						};

	minCashFlow(&graph[0][0],N);					

}