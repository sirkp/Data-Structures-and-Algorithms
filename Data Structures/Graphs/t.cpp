#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	vector<int>::iterator itr1 = v.begin()+1;
	v.erase(v.begin());
	vector<int>::iterator itr2 = v.begin();
	vector<int>::iterator itr3 = v.begin()+1;

		
	cout<<(*itr1)<<" "<<(*itr2)<<" "<<v.size()<<endl;

	if(itr1==itr2)
	cout<<"Ha\n";	
}