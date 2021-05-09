#include<cstdio>
#include<utility>
#include<cstring>
#include<vector>
#include<queue>

# define INF INT_MAX
using namespace std;
int dist[20001];

int main(void){
	int v, e;
	scanf("%d %d", &v, &e);
	int k;
	scanf("%d", &k);
	vector<int> dist(v+1, INF);
	vector<vector<pair<int, int> > > edges(v+1, vector<pair<int, int> >());
	for(int i=0; i<e; i++){
		int u,v,w;
		scanf("%d %d %d", &u, &v, &w);
		edges[u].push_back(make_pair(v,w));
	}
	dist[k]=0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, k));
	while(!pq.empty()){
		pair<int,int> n=pq.top();
		pq.pop();
		for(int i=0;i<edges[n.second].size(); i++){
			if(dist[edges[n.second][i].first]>dist[n.second]+edges[n.second][i].second){
				dist[edges[n.second][i].first]=dist[n.second]+edges[n.second][i].second;
				pq.push(make_pair(dist[edges[n.second][i].first], edges[n.second][i].first));
			}
		}
	}
	for(int i=1;i<=v; i++){
		if(dist[i]==INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}
