#include<cstdio>
#include<vector>
using namespace std;
vector<pair<int, int> > query;
int dist[401][401];

int main(void){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=0;i<k; i++){
		int s, e;
		scanf("%d %d", &s, &e);
		dist[s][e]=-1;
		dist[e][s]=1;
	}
	int nq;
	scanf("%d", &nq);
	for(int i=0;i<nq; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		query.push_back({a, b});
	}

	for(int i=1;i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				if(!dist[j][k]){
					if(dist[j][i]==-1&&dist[i][k]==-1){
						dist[j][k]=-1;
						dist[k][j]=1;
					}
					if(dist[j][i]==1&&dist[i][k]==1){
						dist[j][k]=1;
						dist[k][j]=-1;
					}
				}
			}
		}
	}
	for(auto & q: query){
		printf("%d\n", dist[q.first][q.second]);
	}

}
//Floyed Warshall로 전후관계계산하기

