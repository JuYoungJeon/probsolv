#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
bool cmpAxis(pair<int, int> a, pair<int, int> b){
	if(a.second==b.second) return a.first< b.first;
	return a.second<b.second;
}
int main(void){
	int n;
	scanf("%d", &n);
	vector<pair<int, int> > axis;
	for(int i=0; i<n; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		axis.push_back(make_pair(x, y));
	}
	sort(axis.begin(), axis.end(), cmpAxis);
	for(int i=0; i<n; i++)
		printf("%d %d\n", axis[i].first, axis[i].second);
}
