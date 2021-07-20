#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 100001
using namespace std;

int dp[101][INF];
int caffine[101];

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=1;i<=N; i++){
		scanf("%d", &caffine[i]);
	}
	memset(dp, -1, sizeof(dp));
	for(int i=1; i<=N; i++){
		for(int j=1; j<=K; j++){
			if(caffine[i]==j){
				dp[i][j]=1;
			}else if(caffine[i]<j) {
				if(dp[i-1][j-caffine[i]]!=-1){
					dp[i][j]=dp[i-1][j-caffine[i]]+1;
					if(dp[i-1][j]!=-1) dp[i][j]=min(dp[i][j], dp[i-1][j]);
				}else dp[i][j]=dp[i-1][j];
			}else
				dp[i][j]=dp[i-1][j];
		}
	}
	if (K==0) printf("0");
	else printf("%d", dp[N][K]);
}
