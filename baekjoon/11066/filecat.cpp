#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int pgs[501];
int dp[501][501];
int sum[501];
void memo(int n){
	for(int i=2; i<=n; i++){
		for(int j=i-1; j>=1; j--){
			for(int k=j; k<i; k++){
				int tmp= dp[j][k]+dp[k+1][i]+sum[i]-sum[j-1];
				dp[j][i]= !dp[j][i]? tmp:min(dp[j][i], tmp);
			}
		}
	}
}
int main(void){
	int tc;
	scanf("%d", &tc);
	for(int t=0; t<tc; t++){
		memset(dp, 0, sizeof(dp));
		memset(pgs, 0, sizeof(pgs));
		memset(sum, 0, sizeof(sum));
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++){
			scanf("%d", &pgs[i]);
			sum[i]=sum[i-1]+pgs[i];
		}
		memo(n);
		printf("%d\n", dp[1][n]);
	}
}
//NOTE: sum의 존재이유 
//dp[a][b]=min(dp[a][k]+dp[k+1][b]+sum(b+1)-sum(a)) for k in a..b-1
//dp갱신할때 임시파일에 a~b까지 모두들어감
