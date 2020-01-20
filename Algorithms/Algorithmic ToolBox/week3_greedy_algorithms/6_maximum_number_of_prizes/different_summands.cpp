#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  
  int no = (int)sqrt(n);
  // cout<<no<<" ";
  while(((long long int)no*(no+1)/2)<=n)
  no++;
  no--;
  // cout<<no<<endl;
  
  int capacity = n;
  for(int i=1;i<=no;i++)
  {
    summands.push_back(i);
    capacity-=i;
  }
  
  summands[summands.size()-1]+=capacity;
  // if((summands[summands.size()-1)]==(summands[summands.size()-2)]&&(summands.size()>1))
  // {
  //   summands[summands]
  // }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
