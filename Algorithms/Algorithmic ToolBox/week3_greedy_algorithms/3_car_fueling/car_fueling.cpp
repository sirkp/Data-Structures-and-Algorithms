#include <bits/stdc++.h>
#include <vector>
using namespace std;
using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    stops.push_back(dist);
    int no=0;
    int langer = 0;
    for (int i = 0; i < stops.size(); i++)
    {
        if(i!=0 && (stops[i]-stops[i-1])>tank)
        return -1;
        if((stops[i]-langer)>tank){
            i--;
            no++;
            langer=stops[i];
            // cout<<langer<<" ";
        }      
    }
    
    return no;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
