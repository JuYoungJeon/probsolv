#include<cstdio>
long long dp[1001][1001];
int main(void){
    int n, c;
    scanf("%d %d", &n, &c);
    c=c>n-c?n-c:c;
    if(c==0) {printf("1"); return 0;}
	dp[0][0]=1;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=i; j++){
			if(j==0||j==i){
				dp[i][j]=1;
			}else{
				dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%10007;
			}
		}
	}
	printf("%lld", dp[n][c]);
}
//Note: 파스칼 법칙= nCr=(n-1)Cr+(n-1)C(r-1)
