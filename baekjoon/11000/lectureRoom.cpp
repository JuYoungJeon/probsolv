#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> lectures;
	priority_queue<int, vector<int>, greater<int>> pq;
	int ans=0;
	for(int i=0;i<N; i++){
		int s, e;
		cin >> s>>e;
		lectures.push_back({s, e});
	}
	sort(lectures.begin(), lectures.end());
	for(int i=0;i<N; i++){
		while(!pq.empty()&&pq.top()<=lectures[i].first){
			pq.pop();
		}
		pq.push(lectures[i].second);
		ans=max(ans, (int)pq.size());
	}
	cout << ans;
}
