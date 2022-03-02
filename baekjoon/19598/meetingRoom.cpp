#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int>> meetings;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i=0;i<N; i++){
		int s, e;
		cin >> s >>e;
		meetings.push_back({s, e});
	}
	sort(meetings.begin(), meetings.end());
	pq.push(meetings[0].second);
	int ans=1;
	for(int i=1;i<N; i++){
		pq.push(meetings[i].second);
		while(!pq.empty()&&pq.top() <= meetings[i].first) pq.pop();
		ans=max(ans, pq.size());
	}
	cout << ans;
}
