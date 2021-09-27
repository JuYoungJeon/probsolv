#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
#define pii pair<int, int>
int dp[1002][1002];
queue<pii> q;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int S;
	cin >> S; 
	dp[1][0]=0;
	q.push({1,0});
	while(!q.empty()){
		int cur= q.front().first;
		int curBuf=q.front().second;
		q.pop();
		if(!dp[cur][cur]){
			q.push({cur,cur});
			dp[cur][cur]=dp[cur][curBuf]+1;
		}
		if(cur+curBuf<=S+1&&!dp[cur+curBuf][curBuf]){
			q.push({cur+curBuf, curBuf});
			dp[cur+curBuf][curBuf]=dp[cur][curBuf]+1;
		}
		if(cur-1>=0&&!dp[cur-1][curBuf]){
			q.push({cur-1,curBuf});
			dp[cur-1][curBuf]=dp[cur][curBuf]+1;
		}
	}
	int ans=1001;
	for(int i=1; i<=S; i++)
		ans=min(ans,dp[S][i]);

	cout << ans;
}
