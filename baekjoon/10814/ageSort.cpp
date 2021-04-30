#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
bool cmpPerson(pair<int, string> a, pair<int, string> b){
	return a.first<b.first;
}
int main(void){
	int n;
	cin >> n;
	vector<pair<int, string> > members;
	for(int i=0; i<n; i++){
		int age; string name;
		cin>> age>>name;
		members.push_back(make_pair(age, name));
	}
	stable_sort(members.begin(), members.end(), cmpPerson);
	for(int i=0; i<n; i++)
		cout << members[i].first << ' '<<members[i].second<<'\n';
}
//Note: 순서를 유지하는 stable sort (merge sort)
