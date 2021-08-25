#include<cstdio>
#include<queue>
#include<vector>

using namespace std;
#define pii pair<int, int>
#define INF 987654321

priority_queue<int> dist[1001];

int main(void){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<pii> edges[1001];
	for(int i=0;i<m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges[a].push_back({c, b});
	}
	int start =1;
	dist[start].push(0);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 1});
	while(!pq.empty()){
		int curr = pq.top().second;
		int time = pq.top().first;
		pq.pop();
		for(auto& e: edges[curr]){
			int next = e.second;
			int ntime = e.first+time;
			if(dist[next].size()<k){
				dist[next].push(ntime);
				pq.push({ntime, next});
			}else if(dist[next].top()>ntime){
				dist[next].pop();
				dist[next].push(ntime);
				pq.push({ntime, next});
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(dist[i].size()!=k) printf("-1\n");
		else printf("%d\n", dist[i].top());
	}
}
