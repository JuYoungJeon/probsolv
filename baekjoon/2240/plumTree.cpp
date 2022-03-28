#include<iostream>
#include<cstring>

int dp[1001][31];
int plum[1001];

using namespace std;
int T, W;

int dfs(int idx, int cur, int left){
	if(idx==T) return 0;
	if(dp[idx][left]) return dp[idx][left];
	int notMove, move=0;
	notMove = dfs(idx+1, cur, left)+(plum[idx]==cur);
	if(left>0) move = dfs(idx+1, !(cur-1)+1, left-1)+(plum[idx]==cur);
	return dp[idx][left] = max(notMove, move);
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>> T>> W;
	for(int i=0;i<T; i++){
		cin >> plum[i];
	}
	cout << max(dfs(0, 1, W), dfs(0, 2, W-1)); 
}
