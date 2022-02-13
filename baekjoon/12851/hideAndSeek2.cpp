#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int N, K;
int dp[200000];

void findMinDist(int N){
	queue<int> q;
	q.push(N);
	while(!q.empty()){
		int c = q.front();
		q.pop();
		if(c+1<200000&&(dp[c+1]==-1||dp[c]<dp[c+1])){
			dp[c+1]=dp[c]+1;
			q.push(c+1);
		}
		if(c-1>-1&&(dp[c-1]==-1||dp[c]<dp[c-1])){
			dp[c-1]=dp[c]+1;
			q.push(c-1);
		}
		if(c*2<200000&&(dp[c*2]==-1||dp[c]<dp[c*2])){
			dp[c*2]=dp[c]+1;
			q.push(c*2);
		}
	}
}

int cntPoss(int idx){
	if(idx==N) return 1;
	int nu=0;
	if(dp[idx]==dp[idx-1]+1) nu+=cntPoss(idx-1);
	if(dp[idx]==dp[idx+1]+1) nu+=cntPoss(idx+1);
	if(idx%2==0&&dp[idx]==dp[idx/2]+1) nu+=cntPoss(idx/2);
	return nu;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	memset(dp, -1, sizeof(dp));
	dp[N]=0;
	findMinDist(N);
	cout << dp[K] <<'\n';
	cout << cntPoss(K) ;
}
