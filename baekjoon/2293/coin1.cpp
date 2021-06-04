#include<cstdio>
using namespace std;
int dp[10001];
int main(void){
	int n, k;
	scanf("%d %d", &n, &k);
	int coins[101];
	for (int i=1; i<=n; i++){
		scanf("%d", &coins[i]);
	}
	dp[0]=1;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=k; j++){
			if(j-coins[i]>=0){
				dp[j]+=dp[j-coins[i]];
			}
		}
	}
	printf("%d", dp[k]);
}
