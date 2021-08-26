#include<cstdio>
#include<cstring>
using namespace std;
int dp[1001][1001];
int prev[1001][1001];
int map[1001][1001];
int main(void){
	int n;
	scanf("%d", &n);
	memset(map, -1, sizeof(map));
	memset(prev, -1, sizeof(prev));
	for(int i=1; i<=n; i++){
		for(int j=1;j<=n; j++){
			scanf("%d", &map[i][j]);
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			int top = (prev[i-1][j]+1)%3==map[i][j]?dp[i-1][j]+1:dp[i-1][j];
			int left = (prev[i][j-1]+1)%3==map[i][j]?dp[i][j-1]+1:dp[i][j-1];
			if(top>left){
				dp[i][j]=top;
				if(top>dp[i-1][j]) prev[i][j]=map[i][j];
				else prev[i][j]=prev[i-1][j];
			}else{
				dp[i][j]=left;
				if(left>dp[i][j-1]) prev[i][j]=map[i][j];
				else prev[i][j]=prev[i][j-1];
			}
		}
	}
	printf("%d", dp[n][n]);
}
