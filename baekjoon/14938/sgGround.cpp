#include<cstdio>
#include<queue>
#include<vector>
#define INF 1500
using namespace std;
int dist[101][101];
int item[101];

int main(void){
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);
	for(int i=1; i<=n; i++){
		scanf("%d", &item[i]);
		for(int j=1; j<=n; j++){
			if(i==j) dist[i][j]=0;
			else dist[i][j]=INF;
		}
	}
	for(int i=1; i<=r; i++){
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		dist[a][b]=d;
		dist[b][a]=d;
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				if(dist[j][k]>dist[j][i]+dist[i][k])
					dist[j][k]=dist[j][i]+dist[i][k];
			}
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		int tmp=0;
		for(int j=1; j<=n; j++){
			if(dist[i][j]<=m)tmp+=item[j];
		}
		ans=max(ans, tmp);
	}
	printf("%d", ans);
}
