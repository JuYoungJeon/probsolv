#include<cstdio>
#include<algorithm>
using namespace std;
int map[1001][1001];
int dp[1001][1001];
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%1d", &map[i][j]);
		}
	}
	int ans=0;
	for(int i=1;i<=n; i++){
		for(int j=1;j<=m;j++){
			if(!map[i][j]) continue;
			dp[i][j]=min(dp[i-1][j-1], dp[i-1][j]);
			dp[i][j]=min(dp[i][j], dp[i][j-1]);
			dp[i][j]+=1;
			ans=max(ans, dp[i][j]);
		}
	}
	printf("%d", ans*ans);
}
