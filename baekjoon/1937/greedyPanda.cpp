#include<cstdio>
#include<algorithm>
using namespace std;
int map[501][501];
int dp[501][501];
int dir[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n;

int dfs(int y, int x){
	if(dp[y][x]) return dp[y][x];
	dp[y][x]=1;
	for(int i=0;i<4; i++){
		int dy= y+dir[i][0];
		int dx= x+dir[i][1];
		if(dy<0||dy>=n||dx<0||dx>=n) continue;
		if(map[dy][dx]<=map[y][x]) continue;
		dp[y][x]=max(dp[y][x], dfs(dy, dx)+1);
	}
	return dp[y][x];
}

int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
		}
	}
	int ans=0;
	for(int i=0;i<n; i++){
		for(int j=0;j<n; j++){
			ans=max(ans, dfs(i, j));
		}
	}
	printf("%d", ans);
}
