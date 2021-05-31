#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int dp[501][501];
vector<pair<int, int> > matSize;
int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int r, c;
		scanf("%d %d", &r, &c);
		matSize.push_back(make_pair(r, c));
	}
	for(int i=1; i<N; i++){
		for(int j=i-1; j>=0; j--){
			for(int k=j; k<i; k++){
				if(dp[j][i]!=0) dp[j][i]=min(dp[j][i], dp[j][k]+dp[k+1][i]+matSize[j].first*matSize[k].second*matSize[i].second);
				else dp[j][i]=dp[j][k]+dp[k+1][i]+matSize[j].first*matSize[k].second*matSize[i].second;
			}
		}
	}
	printf("%d", dp[0][N-1]);
}
