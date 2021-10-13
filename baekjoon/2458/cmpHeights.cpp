#include<iostream>
#define INF 501
using namespace std;

int dist[501][501];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N>>M;
	for(int i=1; i<=N; i++) dist[i][i]=1;
	for(int i=0; i<M; i++){
		int a, b;
		cin >> a>>b;
		dist[a][b]=1;
	}
	for(int k=1; k<=N; k++){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(dist[i][k]&&dist[k][j]) dist[i][j]=1;
			}
		}
	}
	int ans=0;
	for(int i=1; i<=N; i++){
		bool con=true;
		for(int j=1; j<=N; j++){
			if(!(dist[i][j]||dist[j][i])){
				con=false; break;
			}
		}
		if(con) ans+=1;
	}
	cout << ans;
}
