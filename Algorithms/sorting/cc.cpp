#include<bits/stdc++.h> 
using namespace std;
int main() 
{ 
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	

	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		if(a==b)
		cout<<-1<<endl;	
		else
		{
			cout<<a<<" "<<b<<endl;
			int count = 0;
			for(int i=1;i<max(a,b);i++)
			{
				cout<<i<<" -> "<<a%i<<" "<<b%i<<endl;
				if(a%i == b%i)
				count++;	
			}	
			cout<<count<<endl;
		}
	}
} 