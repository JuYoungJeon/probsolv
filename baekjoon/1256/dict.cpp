#include<cstdio>
using namespace std;
long long dp[201][101];

int main(void){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	dp[0][0]=1;
	for(int i=1; i<=n+m; i++){
		for(int j=0; j<=i; j++){
			if(j==0) dp[i][j]=1;
			else{
				dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
				if(dp[i][j]>1000000000) dp[i][j]=1000000000;//Maximum of K
			}
		}
	}
	int ans[201];
	int left=m; 
	int j=0;
	if(dp[n+m][m]<k) {printf("-1"); return 0;}
	for(int i=n+m-1; i>=0; i--, j++){
		if(dp[i][left]<k) {ans[j]=1; k-=dp[i][left]; left-=1; }
		else ans[j]=0;
	}
	for(int i=0;i<n+m; i++){
		if(ans[i]) printf("z");
		else printf("a");
	}
}
