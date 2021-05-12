#include<cstdio>
#include<vector>
#include<climits>
#define INF INT_MAX
using namespace std;
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<pair<int, int> > > edges(n+1, vector<pair<int, int> >());
	for(int i=0;i<m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges[a].push_back(make_pair(b, c));
	}
	vector<vector<int> > dist(n+1, vector<int>(n+1, INF));
	for(int i=1; i<=n; i++) dist[i][i]=0;
	for(int i=1; i<=n; i++){
		for(auto &j: edges[i]){
			if(dist[i][j.first]>j.second) dist[i][j.first]=j.second;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				if(dist[j][i]!=INF&& dist[i][k]!=INF&& dist[j][k]>dist[j][i]+dist[i][k]){
					dist[j][k]=dist[j][i]+dist[i][k];
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(dist[i][j]==INF)printf("0 ");
			else printf("%d ", dist[i][j]);
		}
		printf("\n");
	}

}
