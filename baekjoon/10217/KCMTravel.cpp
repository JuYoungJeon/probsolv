#include<cstdio>
#include<vector>
#include<algorithm>
#include<tuple>
#include<queue>
#define INF 987654321

using namespace std;
typedef tuple<int, int, int> tiii;

vector<tiii> edges[101];
int dist[101][10001];
priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

int main(void){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		for(int i=1; i<=n; i++){
			for(int j=0; j<=m; j++)	dist[i][j]=INF;
			edges[i].clear();
		}
		for(int i=1;i<=k;i++){
			int u, v, c, d;
			scanf("%d %d %d %d", &u, &v,&c, &d);
			edges[u].push_back({v, c, d});
		}
		int src=1; int tar=n;
		dist[1][0]=0;
		pq.push({0, 0, 1});
		while(!pq.empty()){
			tiii curr = pq.top();
			pq.pop();
			int nd = get<0>(curr);
			int nc = get<1>(curr);
			int idx= get<2>(curr);
			if(dist[idx][nc]<nd) continue;
			for(auto& next: edges[idx]){
				if(nc+get<1>(next)>m) continue;
				if(dist[get<0>(next)][get<1>(next)+nc]<=nd+get<2>(next)) continue;
				dist[get<0>(next)][get<1>(next)+nc]=nd+get<2>(next);
				pq.push({dist[get<0>(next)][get<1>(next)+nc], nc+get<1>(next), get<0>(next)}); 
			}
		}
		int ans=INF;
		for(int i=1; i<=m; i++)
			ans=min(ans, dist[n][i]);
		if(ans==INF) printf("Poor KCM\n");
		else printf("%d\n", ans);
	}
}
//Dijkstra를 DP를 사용해서 풀기
//거리를 cost별로 기록하기:
