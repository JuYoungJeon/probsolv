#include <iostream>

using namespace std;

int dp[2000][2000];
int num[2000];
int v[2000][2000];

int dfs(int s, int e){
	if(s==e)return 1;
	if(e-s==1){
		v[s-1][e-1]=1;
		if(num[s-1]==num[e-1])
			dp[s-1][e-1]=1;
		else
			dp[s-1][e-1]=0;
		return dp[s-1][e-1];
	}
	if(!v[s-1][e-1]){
		v[s-1][e-1]=1;
		if(num[s-1]!=num[e-1]){
			dp[s-1][e-1]=0;
			return dp[s-1][e-1];
		}else{
			dp[s-1][e-1]=dfs(s+1, e-1);
			return dp[s-1][e-1];
		}
	}else{
		return dp[s-1][e-1];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; 
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> num[i];
		dp[i][i]=1;
		v[i][i]=1;
	}
	int m;
	cin >> m;
	for(int i=0; i<m; i++){
		int s, e;
		cin >> s >> e;
		cout << dfs(s, e)<< '\n';
	}
}

//NOTE: cin -> scanf || ios::sync_with_stdio(false); cin.tie(NULL);
