#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <numeric>
#include <array>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <functional>
#include <locale>
#define     all(v)            v.begin(),v.end()
#define     mp                     make_pair
#define     pb                     push_back
#define     endl                     '\n'

typedef   long long int               ll ;


using namespace std;

ll operation_karo(ll opr1, ll opr2, char oper) {
  if (oper == '*')
    return opr1 * opr2;
  else if (oper == '+')
    return opr1 + opr2;
  else if (oper == '-')
    return opr1 - opr2;
}

ll expr_max(const string &expr) {
  int len = expr.size();
  int num_opr = (len + 1) / 2;

  ll mera_mini[num_opr][num_opr];
  ll mera_max[num_opr][num_opr];

  memset(mera_mini, 0, sizeof(mera_mini)); // initialize to 0
  memset(mera_max, 0, sizeof(mera_max)); // initialize to 0
  for (int i = 0; i < num_opr; i++) {

    mera_mini[i][i] = stoll(expr.substr(2 * i, 1));
    mera_max[i][i] = stoll(expr.substr(2 * i, 1));
  }

  for (int s = 0; s < num_opr - 1; s++) {
    for (int i = 0; i < num_opr - s - 1; i++) {
      int j = i + s + 1;
      ll MinValue = LLONG_MAX;
      ll MaxValue = LLONG_MIN;

      for (int k = i; k < j; k++) {
        ll a = operation_karo(mera_mini[i][k], mera_mini[k + 1][j], expr[2 * k + 1]);
        ll b = operation_karo(mera_mini[i][k], mera_max[k + 1][j], expr[2 * k + 1]);
        ll c = operation_karo(mera_max[i][k], mera_mini[k + 1][j], expr[2 * k + 1]);
        ll d = operation_karo(mera_max[i][k], mera_max[k + 1][j], expr[2 * k + 1]);

        MinValue = min(MinValue, min(a, min(b, min(c, d))));
        MaxValue = max(MaxValue, max(a, max(b, max(c, d))));

      }
      mera_mini[i][j] = MinValue;
      mera_max[i][j] = MaxValue;
    }
  }

  return mera_max[0][num_opr - 1];
}

int main() {
  string Expresion;
  cin >> Expresion;

  cout << expr_max(Expresion) << endl;
}