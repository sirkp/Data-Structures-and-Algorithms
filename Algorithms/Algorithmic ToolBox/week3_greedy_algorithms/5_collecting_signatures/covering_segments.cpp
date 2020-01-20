#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;
using std::vector;

struct Segment {
  int start, end;
};
bool comp(const Segment &a,const Segment &b){
  return(a.start<b.start);
}
vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(),segments.end(),comp);
  // for(int i=0;i<segments.size();i++)
  // cout<<segments[i].start<<" "<<segments[i].end<<endl;
  // cout<<endl;
  //write your code here
  int left=segments[0].start;
  int right=segments[0].end;

  for (int i = 1; i < segments.size(); ++i) {
    if((right-segments[i].start)>=0){
      left=max(left,segments[i].start);
      right=min(right,segments[i].end);
    }
    else{
      points.push_back(left);
      left = segments[i].start;
      right = segments[i].end;
    }
    // cout<<left<<" "<<right<<endl;
  }
  points.push_back(left);

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
