#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int dp[10001];
pair<int, int> loc[10001];

int getDP(int N, int A){
	if(dp[A]!=INT_MAX) return dp[A];
	if(A<=1) return dp[A]=abs(2*loc[A].second);
	int h = 0;
	for(int k=A-1; k>=0; k--){
		h = max(h, abs(loc[k+1].second*2));
		dp[A]=min(dp[A], getDP(N, k)+max(h, abs(loc[A].first-loc[k+1].first)));
	}
	return dp[A];
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for(int i=1;i<=N; i++){
		cin >> loc[i].first>> loc[i].second;
	}
	for(int i=1;i<=N; i++){
		dp[i]=INT_MAX;
	}
	sort(loc+1, loc+N+1);
	cout << getDP(N, N);
}
