#include<cstdio>
using namespace std;
long long dp[10001];
int main(void){
	int num;
	scanf("%d", &num);
	num=num/2;
	dp[0]=1;
	for(int i=1;i<=num; i++){
		for(int j=0; j<i; j++){
			dp[i]=(dp[i]+((dp[j]*dp[i-1-j])%987654321))%987654321;
		}
		dp[i]%=987654321;
	}
	printf("%lld", dp[num]);
}
//NOTE: 카탈랑수열 1,2,5,14, ....
//C(n) = Simga(n-1, i=0) {C(i)*C(n-1-i)}
