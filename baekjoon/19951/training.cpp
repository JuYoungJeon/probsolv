#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>

using namespace std;

int h[100000];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	for(int i=0;i<N; i++) cin >> h[i];
	vector<tuple<int, int, int>> orders;
	for(int i=0; i<M; i++){
		int a, b, k;
		cin >> a>> b>> k;
		orders.push_back({a, b, k});
	}
	sort(orders.begin(), orders.end());
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	int add =0;
	int idx =0;
	for(int i=0;i<N; i++){
		while(idx<M&&get<0>(orders[idx])-1==i) {
			add+=get<2>(orders[idx]);
			pq.push({get<1>(orders[idx]), get<2>(orders[idx])});
			idx+=1;
		}
		h[i]+=add;
		while(!pq.empty()&&pq.top().first-1==i){
			add-=pq.top().second;
			pq.pop();
		}
	}
	for(int i=0;i<N; i++) cout << h[i]<<' ';
}
