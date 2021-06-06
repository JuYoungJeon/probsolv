#include<cstdio>
#include<vector>
#include<climits>
#include<cstring>

#define INF INT_MAX
using namespace std;
int dist[501];
int main(void){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		for(int i=0; i<501; i++) dist[i]=INF;
		int n, m, w;
		scanf("%d %d %d", &n, &m, &w);
		vector<pair<int, int> > edges[501];
		for(int i=0; i<m; i++){
			int s, e, t;//시작, 끝, time
			scanf("%d %d %d", &s, &e, &t);
			edges[s].push_back(make_pair(e, t));
			edges[e].push_back(make_pair(s, t));
		}
		int start=1;
		for(int i=0; i<w; i++){
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			start=s;
			edges[s].push_back(make_pair(e, t*-1));
		}
		dist[start]=0;
		bool negCycle=false;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				for(auto& k: edges[j]){
					if(dist[j]!=INF&&dist[k.first]>dist[j]+k.second){
						dist[k.first]=dist[j]+k.second;
						if(i==n) negCycle=true;
					}
				}
			}
		}
		if(negCycle)printf("YES\n");
		else printf("NO\n");
	}
}

//NOTE:Bellman-ford checking negative cycle
