#include<cstdio>
#include<vector>
#include<queue>
#include<climits>
#define INF INT_MAX
using namespace std;

int main(void){
	int n, e;
	scanf("%d %d", &n, &e);
	vector<vector<int> > dist(3, vector<int>(n+1, INF));
	vector<vector<pair<int, int> > > edges(n+1, vector<pair<int, int> >());
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	for(int i=0;i<e; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges[a].push_back(make_pair(b, c));
		edges[b].push_back(make_pair(a, c));
	}
	int a, b;
	scanf("%d %d", &a, &b);
	//1에서 a/b
	int target[3]={1,a,b};
	for(int j=0;j <3; j++){
		pq.push(make_pair(0,target[j]));
		dist[j][target[j]]=0;
		while(!pq.empty()){
			int c=pq.top().first;
			int v=pq.top().second;
			pq.pop();
			for(auto i=edges[v].begin(); i!=edges[v].end(); i++){
				if(dist[j][i->first]>dist[j][v]+i->second){
					dist[j][i->first]=dist[j][v]+i->second;
					pq.push(make_pair(dist[j][i->first],i->first));
				}
			}
		}
	}
	int first, second;
	if(dist[0][a]==INF||dist[1][b]==INF||dist[2][n]==INF) first=INF;
	else first=dist[0][a]+dist[1][b]+dist[2][n];
	if(dist[0][b]==INF||dist[2][a]==INF||dist[1][n]==INF) second=INF;
	else second=dist[0][b]+dist[2][a]+dist[1][n];
	int minP=min(first,second);
	if(minP==INF) minP=-1;
	printf("%d", minP);
}
//NOTE: 최소거리 계산할때 INF인 경우 합에 대해서 잘 설정하기
