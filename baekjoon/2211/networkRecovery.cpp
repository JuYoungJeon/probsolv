#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define pii pair<int, int>
int dist[1001];
vector<pii> edges[1001];
int conn[1001];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M; 
	cin >> N>>M;
	for(int i=1; i<=N;i++) dist[i]=10001;
	for(int i=0; i<M; i++){
		int a, b, c;
		cin >> a>> b>>c;
		edges[a].push_back({c, b});
		edges[b].push_back({c, a});
	}
	priority_queue<pii, vector<pii>, greater<>> pq;
	pq.push({0, 1});
	dist[1]=0;
	while(!pq.empty()){
		pii curr = pq.top();
		pq.pop();
		for(auto& next:edges[curr.second]){
			if(dist[next.second]>dist[curr.second]+next.first){
				dist[next.second]=dist[curr.second]+next.first;
				conn[next.second]=curr.second;
				pq.push({dist[next.second], next.second});
			}
		}
	}
	cout << N-1<<'\n';
	for(int i=2; i<1001; i++){
		if(conn[i]!=0) cout << i<<' '<<conn[i]<<'\n';
	}

}
