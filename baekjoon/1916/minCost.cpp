#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

#define INF 100000001

using namespace std;

int dist[1001];
vector<pair<int, int>> cost[1001];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N ,M;
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int a, b, c;
		cin >> a>> b>> c;
		cost[a].push_back({c, b});
	}
	int s, e;
	cin >> s>> e;
	for(int i=1; i<=N; i++) dist[i]=INF;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[s]=0;
	pq.push({0, s});
	while(!pq.empty()){
		pair<int, int> c=pq.top();
		pq.pop();
		if(dist[c.second]<c.first) continue;
		for(auto n: cost[c.second]){
			if(dist[n.second]>n.first+c.first){
				dist[n.second]=n.first+c.first;
				pq.push({dist[n.second], n.second});
			}
		}
	}
	cout << dist[e];
}
