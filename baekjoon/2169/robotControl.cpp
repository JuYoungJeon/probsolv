#include<iostream>

using namespace std;

int dir[3][2]={{0,1},{0,-1},{1,0}};

int map[1001][1001];
int visited[1001][1001];
int dp[1001][1001][3];
int run(int N, int M, int y, int x, int d){
	if(y==N&&x==M) return map[y][x];
	if(dp[y][x][d]!=-100000000) return dp[y][x][d];
	visited[y][x]=1;
	int tmp=-100000000;
	for(int i=0;i<3; i++){
		int ny=y+dir[i][0];
		int nx=x+dir[i][1];
		if(ny<1||nx<1||ny>N||nx>M) continue;
		if(visited[ny][nx]) continue;
		tmp=max(tmp, run(N, M, ny, nx, i));
	}
	dp[y][x][d]=map[y][x]+tmp;
	visited[y][x]=0;
	return dp[y][x][d];
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for(int i=1;i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> map[i][j];
			dp[i][j][0]=-100000000;
			dp[i][j][1]=-100000000;
			dp[i][j][2]=-100000000;
		}
	}
	cout << run(N, M, 1, 1, 0);
}
