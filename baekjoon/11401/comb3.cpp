#include<cstdio>
#define P 1000000007
long long dp[4000001];

long long power(int a, int n){
	if(n==1) return a%P;
	long long ret=power(a, n/2);
	ret=(ret*ret)%P;
	if(n%2!=0)
		ret=(ret*a)%P;
	return ret;
}
int main(void){
	int n, k;
	scanf("%d %d", &n, &k);
	//n!
	dp[0]=1;
	dp[1]=1;
	for(int i=2; i<=n; i++)
		dp[i]=(dp[i-1]*i)%P;
	//a^(p-2)
	long long ans=dp[n];
	ans=(ans*power(dp[n-k], P-2))%P;
	ans=(ans*power(dp[k], P-2))%P;
	printf("%lld", ans);
}
//Note: 파스칼의 소정리 
// prime number: p, number not divisible by p: a
// a^(p-1)=1(%p)
// a^p=a(%p)
// a^(p-2)*a=1(%p)
// therefore, a^(p-2) is inverse of a when mod by p
// nCr=n!/((n-r)!r!) 
// 1/((n-r)! r!)%p = ((n-r)!r!)^(p-2)
