#include<cstdio>
#define MOD 1000000000
using namespace std;

int n;
long long dp[101][10][1<<10];

int main(void){
	scanf("%d", &n);
	for(int i=1; i<10; i++)
		dp[1][i][1<<i]=1;
	for(int i=2;i<=n; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<(1<<10); k++){
				if(j-1>=0)
					dp[i][j][k|(1<<j)]=(dp[i][j][k|(1<<j)]+dp[i-1][j-1][k])%MOD;
				if(j+1<10)
					dp[i][j][k|(1<<j)]=(dp[i][j][k|(1<<j)]+dp[i-1][j+1][k])%MOD;
			}
		}
	}
	long long sum=0;
	for(int i=0;i<10; i++){
		sum=(sum+dp[n][i][(1<<10)-1])%MOD;
	}
	printf("%lld", sum);
}
