#include<iostream>
#include<algorithm>

using namespace std;

int dp[2][1000001];

int main(void){
	int n;
	cin >> n;
	string dna;
	cin >> dna;
	if(dna[0]=='A')dp[1][0]=1;
	else dp[0][0]=1;
	for(int i=1; i<dna.size(); i++){
		if(dna[i]=='A') {
			dp[0][i]=min(dp[0][i-1], dp[1][i-1]+1);
			dp[1][i]=min(dp[1][i-1]+1, dp[0][i-1]+1);
		}else{
			dp[0][i]=min(dp[0][i-1]+1, dp[1][i-1]+1);
			dp[1][i]=min(dp[1][i-1], dp[0][i-1]+1);
		}
	}
	cout << min(dp[0][dna.size()-1], dp[1][dna.size()-1]+1);
}
//Note: DP[0][i] -> i번째 idx까지 A인경우, DP[1][i] -> i 번째까지 B인경우
