#include <bits/stdc++.h>
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
		int n,x;
		cin>>n>>x;

		string s;
		cin>>s;

		int count_1 = 0;
		int count_0 = 0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1')
			count_1++;
			else
			count_0++;	
		}	

		int diff_arr[n];
		if(s[0]=='0')
		diff_arr[0] = 1;
		else
		diff_arr[0] = -1;	

		for(int i=1;i<n;i++)
		if(s[i]=='0')
		diff_arr[i] = diff_arr[i-1]+1;
		else
		diff_arr[i] = diff_arr[i-1]-1;
		
		int diff = count_0-count_1;

		if(diff==x)
		cout<<-1<<endl;
		else if(diff==0)
		{
			bool check = false;
			for(int i=1;i<n;i++)
			if(diff_arr[i]==x)
			{
				check = true;
				break;
			}

			if(check)
			cout<<-1<<endl;
			else
			cout<<0<<endl;	
		}
		else
		{

			int q = abs(x)/abs(diff);
			if(q==0)
			{
				int count = 0;
				int d = q*diff;
				for(int i=1;i<n;i++)
				if((diff_arr[i]+d)==x)
				count++;

				d = (q+1)*diff;
				for(int i=1;i<n;i++)
				if((diff_arr[i]+d)==x)
				count++;

				if(x==0)
				cout<<count+1<<endl;
				else
				cout<<count<<endl;
			}
			else
			{
				int count = 0;
				int d = (q-1)*diff;
				
				for(int i=1;i<n;i++)
				if((diff_arr[i]+d)==x)
				count++;

				d = q*diff;
				for(int i=1;i<n;i++)
				if((diff_arr[i]+d)==x)
				count++;

				d = (q+1)*diff;
				for(int i=1;i<n;i++)
				if((diff_arr[i]+d)==x)
				count++;

				d = (q+2)*diff;
				for(int i=1;i<n;i++)
				if((diff_arr[i]+d)==x)
				count++;

				d = (q+3)*diff;
				for(int i=1;i<n;i++)
				if((diff_arr[i]+d)==x)
				count++;

					d = (q+4)*diff;
				for(int i=1;i<n;i++)
				if((diff_arr[i]+d)==x)
				count++;


				cout<<count<<endl;								
			}
		}	
	}	
}