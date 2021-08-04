#include<cstdio>
using namespace std;
long long dp[21];
long long getDP(int n){
	if(dp[n]) return dp[n];
	dp[n]=(n-1)*(getDP(n-1)+getDP(n-2));
	return dp[n];
}
int main(void){
	int tc;
	scanf("%d", &tc);
	dp[2]=1;
	while(tc--){
		int N;
		scanf("%d", &N);
		printf("%lld\n",getDP(N));
	}
}
