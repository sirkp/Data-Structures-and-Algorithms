#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  unordered_map<int,int> umap;
  for(int i=0;i<a.size();i++)
  {
    if(umap.find(a[i])==umap.end())
    umap[a[i]]=1;
    else
    umap[a[i]]++;
  }

  for(auto i:umap)
  {
    if(i.second>(a.size()/2))
    return 1;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
