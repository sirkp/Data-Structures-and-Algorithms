#include<bits/stdc++.h> 
#define MOD 1000000007
using namespace std;
long long int moduloMultiplication(long long int a, 
                            long long int b, 
                            long long int mod) 
{ 
    long long int res = 0; // Initialize result 
  
    // Update a if it is more than 
    // or equal to mod 
    a %= mod; 
  
    while (b) 
    { 
        // If b is odd, add a with result 
        if (b & 1) 
            res = (res + a) % mod; 
  
        // Here we assume that doing 2*a 
        // doesn't cause overflow 
        a = (2 * a) % mod; 
  
        b >>= 1; // b = b / 2 
    } 
  
    return res; 
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
		long long int a,b;
		cin>>a>>b;
		
		long long int n = log2(min(a,b));
		long long int no = (long long int)pow(2,n+1) - (long long int)pow(2,n);

		long long int ans = moduloMultiplication(no,min(a,b),MOD);
		// for(int i=0;i<no;i++)
		// {
		// 	ans = ((ans%MOD) + (min(a,b)%MOD))%MOD;
		// }
		cout<<ans<<endl;
	}
} 