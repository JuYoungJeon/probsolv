#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int dp[17];
int main(void){
	int N;
	scanf("%d", &N);
	vector<pair<int, int> > c;
	int maxV=0;
	for(int i=1; i<=N; i++){
		dp[i]=max(dp[i], dp[i-1]);
		int t, p;
		scanf("%d %d", &t, &p);
		if(i+t>N+1) continue;
		dp[i+t]=max(dp[i+t], dp[i]+p);
		maxV = max(maxV, dp[i+t]);
	}
	printf("%d", maxV);
}
