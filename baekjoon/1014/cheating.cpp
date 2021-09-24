#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int dir[6][2]={{-1,-1},{0,-1},{1,-1},{1,1}, {-1,1},{0,1}};
int acqA[51];
int acqB[51];
int visited[51];
vector<int> adj[51];
string map[11];
int idxes[11][11];

bool dfs(int x){
	if(visited[x]) return false;
	visited[x]=1;
	for(int e:adj[x]){
		if(acqB[e]==0||dfs(acqB[e])){
			acqA[x]=e;
			acqB[e]=x;
			return true;
		}
	}
	return false;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int C;
	cin >> C;
	while(C--){
		memset(acqA, 0, sizeof(acqA));
		memset(acqB, 0, sizeof(acqB));
		int N, M;
		cin >> N>>M;
		for(int i=0;i<N; i++){
			cin>> map[i];
		}
		int cntBroken=0;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(map[i][j]=='x') cntBroken+=1;
			}
		}
		int aidx=1, bidx=1;
		for(int i=0;i<N; i++){
			for(int j=0;j<M; j+=2){
				adj[aidx].clear();
				idxes[i][j]=aidx++;
			}
			for(int j=1; j<M; j+=2){
				idxes[i][j]=bidx++;
			}
		}
		for(int i=0; i<N; i++){
			for(int j=0;j<M; j+=2){
				if(map[i][j]=='x') continue;
				for(int d=0; d<6; d++){
					int ny = i+dir[d][0];
					int nx = j+dir[d][1];
					if(ny<0||nx<0||ny>=N||nx>=M) continue;
					if(map[ny][nx]=='x') continue;
					adj[idxes[i][j]].push_back(idxes[ny][nx]);
				}
			}
		}
		int ans=0;
		for(int i=0; i<aidx; i++){
			memset(visited,0, sizeof(visited));
			if(dfs(i)) ans+=1;;
		}
		cout << N*M-ans-cntBroken<<'\n';
	}
}
