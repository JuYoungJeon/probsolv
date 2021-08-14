#include<cstdio>
#define ll long long

using namespace std;

ll dp[31][31];

ll getCase(int w, int h){
	if(dp[w][h]) return dp[w][h];
	if(w==0) return dp[w][h]=1;
	dp[w][h]=getCase(w-1, h+1);
	if(h>0) dp[w][h]+=getCase(w, h-1);
	return dp[w][h];	
}

int main(void){
	while(1){
		int n;
		scanf("%d", &n);
		if(n==0) return 0;
		ll ans = getCase(n, 0);
		printf("%lld\n", ans);
	}
}
