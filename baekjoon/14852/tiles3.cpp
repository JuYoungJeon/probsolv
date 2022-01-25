#include<iostream>
#include<cstring>
using namespace std;

#define REM 1000000007

long dp[1000001][2];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	memset(dp, 0, sizeof(dp));
    int N;
    cin >> N;
    dp[0][0]=0;
	dp[1][0]=2;
	dp[2][0]=7;
    dp[2][1]=1;
    for(int i=3; i<=N; i++){
		dp[i][1]=(dp[i-3][0]+dp[i-1][1])%REM;
        dp[i][0]=(dp[i-1][0]*2%REM+dp[i-2][0]*3%REM+(dp[i][1]*2)%REM)%REM;
    }
    cout << dp[N][0];
}
