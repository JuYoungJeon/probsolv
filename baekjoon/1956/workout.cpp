#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
#define INF INT_MAX

using namespace std;
int main(void){
	int v, e;
	scanf("%d %d", &v, &e);
	vector<vector<int> > dist(v+1, vector<int>(v+1, INF));
	vector<vector<pair<int, int> > > edges(v+1, vector<pair<int, int> >());
	for(int i=0;i<e;i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b]=c;
	}
	for(int i=1; i<=v; i++) dist[i][i]=0;
	for(int i=1; i<=v ;i++) {
		for(int j=1; j<=v; j++){
			for(int k=1; k<=v; k++){
				if(dist[j][i]!=INF&& dist[i][k]!=INF&&dist[j][k]>dist[j][i]+dist[i][k])
					dist[j][k]=dist[j][i]+dist[i][k];
			}
		}
	}
	int minDist=INF;
	for(int i=1; i<=v; i++){
		for(int j=1; j<=v; j++){
			if(i==j) continue;
			if(dist[i][j]==INF|| dist[j][i]==INF) continue;
			minDist=min(minDist, dist[i][j]+dist[j][i]);
		}
	}
	if(minDist==INF)printf("-1");
	else printf("%d",minDist);
}
//NOTE: cycle을 찾는 것이기 때문에 자기자신을 0으로 할 필욘없음
