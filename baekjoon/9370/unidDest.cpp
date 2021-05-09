#include<cstdio>
#include<vector>
#include<queue>
#include<climits>
#include<iostream>
#define INF INT_MAX
using namespace std;
int main(void){
	int tc;
	scanf("%d", &tc);
	for(int i=0; i<tc ;i++){
		int n, m, t;//intersection, street, numTarget
		scanf("%d %d %d", &n, &m, &t);
		int s, g, h;//startpos, two intersections that must pass
		scanf("%d %d %d", &s, &g, &h);
		vector<vector<pair<int, int> > >edges(n+1, vector<pair<int, int> > ());
		for(int j=0; j<m; j++){
			int a, b, d;
			scanf("%d %d %d", &a, &b, &d);
			edges[a].push_back(make_pair(b, d));
			edges[b].push_back(make_pair(a, d));
		}
		vector<int> target;
		for(int j=0; j<t; j++) {
			int tar;
			scanf("%d", &tar);
			target.push_back(tar);
		}
		//s에서 shortest path
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		int from[3]={s, g, h};
		vector< vector<int> > dist(3, vector<int>(n+1, INF));
		for(int j=0; j<3; j++){
			dist[j][from[j]]=0;
			pq.push(make_pair(dist[j][from[j]], from[j]));
			while(!pq.empty()){
				int w=pq.top().first;
				int u=pq.top().second;
				pq.pop();
				for(auto edge=edges[u].begin(); edge!=edges[u].end(); edge++){
					if(dist[j][edge->first]>dist[j][u]+edge->second){
						dist[j][edge->first]=dist[j][u]+edge->second;
						pq.push(make_pair(dist[j][edge->first],edge->first));
					}
				}
			}
		}
		priority_queue<int, vector<int>, greater<int> > ans;
		for(auto tar=target.begin(); tar!=target.end(); tar++){
			//s->h->g->t
			int shgt;
			if(dist[0][h]==INF||dist[2][g]==INF||dist[1][*tar]==INF) shgt=INF;
			else shgt=dist[0][h]+dist[2][g]+dist[1][*tar];
			//s->g->h->t
			int sght;
			if(dist[0][g]==INF||dist[1][h]==INF||dist[2][*tar]==INF) sght=INF;
			else sght=dist[0][g]+dist[1][h]+dist[2][*tar];
			if(dist[0][*tar]==INF) continue;
			if(dist[0][*tar]==shgt||dist[0][*tar]==sght) ans.push(*tar);
		}
		while(!ans.empty()){
			int a=ans.top();
			ans.pop();
			printf("%d ", a);
		}
		printf("\n");
	}
}
