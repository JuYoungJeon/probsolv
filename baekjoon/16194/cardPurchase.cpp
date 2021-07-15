#include<cstdio>
#include<algorithm>
using namespace std;
int dp[1001];
int card[1001];
void getMinCost(int n){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			dp[i]=min(dp[i], card[j]+dp[i-j]);
		}
	}
}
int main(void){
	int n; 
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &card[i]);
		dp[i]=10000*n;
	}
	getMinCost(n);
	printf("%d", dp[n]);
}
