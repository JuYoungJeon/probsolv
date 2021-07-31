#include<iostream>
#include<algorithm>

using namespace std;

int dp[2001][2001];
int val[2001];

int getVal(int s, int e, int idx){
	if(dp[s][e]) return dp[s][e];
	if(s>e) return 0;
	return dp[s][e]=max(getVal(s+1, e, idx+1)+val[s]*idx, getVal(s, e-1,idx+1)+val[e]*idx);
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i=1;i<=n; i++){
		cin >> val[i];
	}
	cout << getVal(1, n, 1);
}
//Note: DP를 val보다 먼저선언해아함.. 아니면 틀림..왜...???
