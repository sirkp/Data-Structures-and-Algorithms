#include <iostream>
using namespace std;
int get_change(int m) {
  int arr[3]={10,5,1};
  int n=0;
  for(int i=0;i<3;i++){
    n+=(m/arr[i]);
    m%=arr[i];
  }  
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
