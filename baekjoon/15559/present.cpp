#include<iostream>
#include<cstring>

using namespace std;

int par[1000001];
int N, M;
char map[1000][1000];

int find(int a){
	if(par[a]==a) return par[a];
	else return par[a]=find(par[a]);
}

void uni(int a, int b){
	int pa=find(a);
	int pb=find(b);
	if(pa!=pb){
		par[pa]=pb;
	}
}

int dir2Idx(int y, int x){
	if(map[y][x]=='N') return (y-1)*M+x;
	else if(map[y][x]=='S') return (y+1)*M+x;
	else if(map[y][x]=='W') return y*M+(x-1);
	else return y*M+(x+1);
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	int ans=0;
	for(int i=0;i<N*M; i++) par[i]=i;
	for(int i=0;i<N; i++){
		for(int j=0;j<M; j++){
			cin >> map[i][j];
		}
	}
	for(int i=0;i<N; i++){
		for(int j=0;j<M; j++){
			uni(i*M+j, dir2Idx(i, j));
		}
	}
	for(int i=0;i<N*M; i++){
		if(par[i]==i) ans+=1;
	}
	cout << ans;
}
