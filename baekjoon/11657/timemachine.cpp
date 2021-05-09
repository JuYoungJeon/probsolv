#include<cstdio>
#include<vector>
#include<climits>
#define INF INT_MAX
using namespace std;
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<pair<int, int> > >edges(n+1, vector<pair<int, int> >());
	vector<long > dist(n+1, INF);
	for(int i=0;i<m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges[a].push_back(make_pair(b, c));
	}
	dist[1]=0;
	bool cycle=false;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(auto &k:edges[j]){
				if(dist[j]!=INF&&dist[k.first]>dist[j]+k.second){
					dist[k.first]=dist[j]+k.second;
					if(i==n){cycle=true; break;}
				}
			}
		}
	}
	if(cycle)printf("-1");
	else {
		for(int i=2; i<=n; i++){
            if(dist[i]==INF) printf("-1\n");
            else printf("%ld\n", dist[i]);	
		}
	}
}
//Note: 출력초과-> Bellman-ford는 음의 cycle 생길수 있기에 underflow 일어날 수 있다.
// 최소값 갱신불가로 인한 underflow->dist를 longlong 으로 설정
