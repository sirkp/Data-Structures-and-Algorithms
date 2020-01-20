#include <bits/stdc++.h>
#define     all(v)            v.begin(),v.end()
#define     mp                     make_pair
#define     pb                     push_back
#define     endl                     '\n'

typedef   long long int               ll;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

using namespace std;
int countMin(int sikka[], int nwa, int paisa) {
	vector<int> rasta(paisa + 1, INT_MAX);
	rasta[0] = 0;
	for (int ii = 1; ii <= paisa; ii++) {
		for (int cc = 0; cc < nwa; cc++) {
			if (ii >= sikka[cc]) {
				int su_re = rasta[ii - sikka[cc]];
				if (su_re != INT_MAX && su_re + 1 < rasta[ii])
					rasta[ii] = su_re + 1;
			}
		}
	}
	return rasta[paisa];
}
int main() {
	int paisa; 
	cin >> paisa; 
	int sikka[3] = { 1,3,4 };
	cout << countMin(sikka, 3, paisa) << endl;

}