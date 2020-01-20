#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <functional>
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define endl '\n'

typedef long long int ll;

using namespace std;
int knapsack(int W, vector<int> my_val, vector<int> weig, int no) {
  
  vector<vector<int>>  K(no + 1,vector<int>(W + 1));
  for (int ii = 0; ii <= no; ii++) {
    for (int w = 0; w <= W; w++) {
      if (ii == 0 || w == 0)
        K[ii][w] = 0;
      else if (weig[ii - 1] <= w)
        K[ii][w] = max(my_val[ii - 1] + K[ii - 1][w - weig[ii - 1]], K[ii - 1][w]);
      else
        K[ii][w] = K[ii - 1][w];
    }
  }

  return K[no][W];
}

int main() {
  int no, Capas;
  cin >> Capas >> no;

  vector<int> Values(no);
  vector<int> Weights(no);
  int Temp;
  for (size_t ii = 0; ii < no; ii++) {
    cin >> Temp;
    Values[ii] = Weights[ii] = Temp;
  }
  cout << knapsack(Capas, Values, Weights, no) << endl;
}