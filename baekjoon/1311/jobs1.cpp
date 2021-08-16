#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 1e9
using namespace std;
int dp[20][1<<21], arr[20][20];
int n;

int dfs(int cur, int bit){
	if(cur>=n) return 0;
	if(dp[cur][bit]!=-1) return dp[cur][bit];
	dp[cur][bit]=INF;
	for(int i=0; i<n; i++){
		if(!(bit&(1<<i))){
			dp[cur][bit]=min(dp[cur][bit], dfs(cur+1, bit|(1<<i))+arr[cur][i]);
		}
	}
	return dp[cur][bit];
}

int main(void){
	scanf("%d", &n);
	for(int i=0;i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d", dfs(0, 0));
}
