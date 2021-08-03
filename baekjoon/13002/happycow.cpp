#include<cstdio>
#include<algorithm>
using namespace std;
int dp[2001][2001];
int food[2001];
int getDP(int s, int e, int idx){
	if(dp[s][e]) return dp[s][e];
	if(s>e) return 0;
	dp[s][e]=max(getDP(s+1, e, idx+1)+food[s]*idx, getDP(s, e-1, idx+1)+food[e]*idx);
	return dp[s][e];
}
int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &food[i]);
	}
	printf("%d", getDP(1, N, 1));
}
