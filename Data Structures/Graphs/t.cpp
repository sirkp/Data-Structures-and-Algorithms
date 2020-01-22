#include <bits/stdc++.h>
using namespace std;
#define N 5

bool horizontal(int x,int y,int arr[N+1][N+1])
{
	for(int i=y+1;i<=N;i++)
	if(arr[x][i]==1)
	return true;

	return false;	
}
bool vertical(int x,int y,int arr[N+1][N+1])
{
	for(int i=x+1;i<=N;i++)
	if(arr[i][y]==1)
	return true;

	return false;	
}

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
		int arr[N+1][N+1] = {0};
		for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)
		arr[i][j]=0;	
		int n;
		cin>>n;

		int x,y;
		for(int i=0;i<n;i++)
		{
			cin>>y>>x;
			arr[x][y] = 1;
		}

		int count = 0;
		x=0;
		y=0;
		bool check_horizontal;
		bool check_vertical;

		// cout<<endl;
		// for(int i=0;i<=N;i++)
		// {
		// 	for(int j=0;j<=N;j++)
		// 	cout<<arr[i][j]<<" ";
		// 	cout<<endl;	
		// }

		// cout<<endl;
		bool atom = false;
		string s = "";
		int cc = 1;
		while(count<n)
		{
			// cout<<count<<"**\n";
			// cout<<y<<" "<<x<<endl;
			check_horizontal = horizontal(x,y,arr);
			check_vertical = vertical(x,y,arr);

			// cout<<"ch- "<<check_horizontal<<"   cv- "<<check_vertical<<endl;
			if(check_vertical&&check_horizontal)
			{
				cout<<"NO\n";
				atom = true;
				break;
			}
			else if(check_horizontal)
			{
				int i;
				for( i=y+1;i<=N;i++)
				{
					s+="R";
					// cout<<"R\n";
					if(arr[x][i]==1)
					{
						// cout<<"yes "<<i<<endl;
						count++;
						break;	
					}
				}	
				y =i;
			}
			else if(check_vertical)
			{
				int i;
				for( i=x+1;i<=N;i++)
				{
					// cout<<"U\n";
					s+="U";
					if(arr[i][y]==1)
					{
					// cout<<"yes "<<i<<endl;
						count++;
						break;	
					}	
				}	
				x =i;	
			}
			else
			{
				s+="R";
				// cout<<"R\n";
				y = y+1;
			}	
			// cout<<endl;
		// if(cc==16)
		// 	break;

		// cc++;
		}
		if(!atom)
		{
			cout<<"YES\n";
			cout<<s<<endl;	
		}



	}	
}	