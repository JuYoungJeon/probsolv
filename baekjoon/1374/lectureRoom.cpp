#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define pii pair<int, int>
vector<pii> ls;
int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; 
	cin >> n;
	for(int i=0;i<n; i++){
		int idx, s, e;
		cin >> idx >> s >> e;
		ls.push_back({s, e});
	}
	sort(ls.begin(), ls.end());
	int ans=0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0;i<n; i++){
		if(!pq.empty()&&pq.top()<=ls[i].first){
			pq.pop();
		}else{
			ans+=1;
		}
		pq.push(ls[i].second);
	}
	cout << ans;
}
