#include <iostream>

int gcd_naive(int a, int b) {
  if(a==0)
  return b;
  else
  return gcd_naive(b%a,a);  
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}
