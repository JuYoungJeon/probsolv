#include<cstdio>
#include<utility>
#include<vector>
#include<cstring>
using namespace std;
int dp[101][100001];
vector<pair<int,int> > obj;
int main(void){
	memset(dp, 0, sizeof(dp));
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=0;i<n; i++){
		int w, v;
		scanf("%d %d",&w, &v);
		obj.push_back(make_pair(w, v));
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=k; j++)
			if(obj[i-1].first<=j) dp[i][j]=max(dp[i-1][j-obj[i-1].first]+obj[i-1].second, dp[i-1][j]);
			else dp[i][j]=dp[i-1][j];
	}
	printf("%d", dp[n][k]);
}
//NOTE: knapsack problem 
