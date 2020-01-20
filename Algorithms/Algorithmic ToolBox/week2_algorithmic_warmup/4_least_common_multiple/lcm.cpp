#include <iostream>

long long int gcd(int a,int b)
{
	if(a==0)
	return b;	
	else
	return gcd(b%a,a);	
}

long long int lcm_naive(int a, int b)
{
	long long int lcm= (a/gcd(a,b))*b; 	 
  	return lcm;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
