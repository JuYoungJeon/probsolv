#include <cstdio>
#include <queue>
using namespace std;
int dp[501][501];
int visited[501][501];
int map[501][501];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
queue<pair<int, int> > q;
void bfs(int m, int n){
	visited[0][0]=1;
	q.push(make_pair(0,0));
	while(!q.empty()){
		pair<int, int> next = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int y = next.first+dir[i][0];
			int x = next.second+dir[i][1];
			if(y<0||x<0||y>=m||x>=n) continue;
			if(map[y][x]>=map[next.first][next.second]) continue;
			if(!visited[y][x])q.push(make_pair(y, x));
			visited[y][x]+=1;
		}
	}
	q.push(make_pair(0,0));
	dp[0][0]=1;
	while(!q.empty()){
		pair<int, int> next = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int y= next.first+dir[i][0];
			int x=next.second+dir[i][1];
			if(y<0||x<0||y>=m||x>=n) continue;
			if(map[y][x]>=map[next.first][next.second]) continue;
			visited[y][x]-=1;
			dp[y][x]+=dp[next.first][next.second];
			if(!visited[y][x])q.push(make_pair(y, x));
		}
	}
}

int main(void){
	int m, n;
	scanf("%d %d", &m, &n);
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
		}
	}
	bfs(m, n);
	dp[0][0]=1;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("%d", dp[m-1][n-1]);
}
