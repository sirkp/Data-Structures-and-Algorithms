#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define endl '\n'
typedef long long int ll;
using namespace std;
int editDistDP(string stringwa1, string stringwa2, int mwa, int nwa) {
	vector<vector<int>> hamar_dp(mwa + 1, vector<int>(nwa + 1));

	for (int i = 0; i <= mwa; i++) {
		for (int j = 0; j <= nwa; j++) {
			if (i == 0)
				hamar_dp[i][j] = j;

			else if (j == 0)
				hamar_dp[i][j] = i;

			else if (stringwa1[i - 1] == stringwa2[j - 1])
				hamar_dp[i][j] = hamar_dp[i - 1][j - 1];

			else
				hamar_dp[i][j] = 1 + min(min(hamar_dp[i][j - 1], hamar_dp[i - 1][j]), hamar_dp[i - 1][j - 1]);
		}
	}

	return hamar_dp[mwa][nwa];
}
int main() {
	string pehla_string, dusraka_string;
	cin >> pehla_string >> dusraka_string;
	
	cout << editDistDP(pehla_string, dusraka_string, pehla_string.size(),
		dusraka_string.size())
		<< endl;
}