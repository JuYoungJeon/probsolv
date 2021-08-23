#include<cstdio>
#include<algorithm>
using namespace std;
int dp[101][1001];

int main(void){
	int n,s,m;
	scanf("%d %d %d", &n, &s, &m);
	dp[0][s]=1;
	for(int i=1;i<=n; i++){
		int vol;
		scanf("%d", &vol);
		for(int j=0; j<=m; j++){
			if(!dp[i-1][j]) continue;
			if(j-vol>=0) dp[i][j-vol]=1;
			if(j+vol<=m) dp[i][j+vol]=1;
		}
	}
	int ans=-1;
	for(int i=0; i<=m; i++){
		if(dp[n][i]) ans=i;
	}
	printf("%d", ans);
}
