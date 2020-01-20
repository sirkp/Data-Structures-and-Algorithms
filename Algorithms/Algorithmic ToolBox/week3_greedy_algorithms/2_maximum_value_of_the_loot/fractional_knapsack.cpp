#include <bits/stdc++.h>
using namespace std;

using std::vector;
bool sortbysec(const pair<int,double> &a, const pair<int,double> &b){ 
  return (a.second > b.second); 
}
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  
  vector<pair<int,double>> aukat;
  
  for(int i=0;i<values.size();i++)
  aukat.push_back(make_pair(i,(double)values[i]/weights[i]));
  
  sort(aukat.begin(),aukat.end(),sortbysec);
  // for(int i=0;i<aukat.size();i++)
  // cout<<aukat[i].first<<" "<<aukat[i].second<<"   ";
  // cout<<endl;

  int i=0;
  while(i<aukat.size()){
    int weight = min(weights[aukat[i].first],capacity);
    value=(double)(value+(double)(weight*aukat[i].second));
    capacity=(double)(capacity-weight);
    i++;
    // cout<<value<<" "<<capacity<<endl;
  }



  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  // std::cout.precision(4);
  std::cout<<fixed<<setprecision(4)<< optimal_value << std::endl;
  return 0;
}
