#include<iostream>

using namespace std;

int num[5001];
int dp[5001][5001];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for(int i=1;i<=N; i++) cin >> num[i];

	int ans=0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(num[i]==num[N-j+1])dp[i][j]=dp[i-1][j-1]+1;
			dp[i][j]=max(dp[i][j], dp[i-1][j]);
			dp[i][j]=max(dp[i][j], dp[i][j-1]);
			ans=max(ans, dp[i][j]);
		}
	}
	cout << N-ans;
	
}
