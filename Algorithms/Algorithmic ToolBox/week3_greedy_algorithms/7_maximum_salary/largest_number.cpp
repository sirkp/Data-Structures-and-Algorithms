#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;
using std::string;
bool comp(const string &a, const string &b){
    stringstream s_ab(a+b);
    stringstream s_ba(b+a);
    int ab=0;
    s_ab>>ab;
    int ba=0;
    s_ba>>ba;
    // cout<<ab<<" "<<ba<<endl;
    return (ab>ba);
}
string largest_number(vector<string> a) {
  //write your code here
  sort(a.begin(),a.end(),comp);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    // cout<<a[i]<<" ";
    ret << a[i];
  }
  // cout<<endl;
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
