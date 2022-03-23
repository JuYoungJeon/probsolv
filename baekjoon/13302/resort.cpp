#include<iostream>
#include<cstring>

#define ONEDAY 10000
#define THREEDAYS 25000
#define FIVEDAYS 37000

using namespace std;

int dp[101][101];
int unavail[101];
int N, M;

int dfs(int date, int coup, int cost){
	if(date>N) return cost;
	if(dp[date][coup]) return dp[date][coup];
	if(unavail[date]) return dfs(date+1, coup, cost);

	int ans = min(dfs(date+1, coup, cost)+ONEDAY, dfs(date+3, coup+1, cost)+THREEDAYS);
	ans = min(ans, dfs(date+5, coup+2, cost)+FIVEDAYS);
	if(coup>=3) ans = min(ans, dfs(date+1, coup-3, cost));
	dp[date][coup]=ans;
	return dp[date][coup];
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N>>M;
	for(int i=0;i<M; i++){
		int t;
		cin >> t;
		unavail[t]=1;
	}
	cout <<dfs(1, 0, 0);
}
