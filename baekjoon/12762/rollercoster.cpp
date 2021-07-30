#include<iostream>
#include<algorithm>
using namespace std;
int heights[1001];
int dp[1001];
int dpRev[1001];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i=1;i<=N; i++){
		cin >> heights[i];
	}
	for(int i=1; i<=N; i++){
		dp[i]=1; // 초기값은 1로 해주어야함 모든 원소에 대해서 
		for(int j=1; j<i; j++){
			if(heights[i]<heights[j]){
				if(dp[i]<dp[j]+1) dp[i]=dp[j]+1;
			}
		}
	}
	for(int i=N; i>=1; i--){
		dpRev[i]=1;
		for(int j=N; j>i; j--){
			if(heights[i]<heights[j]){
				if(dpRev[i]<dpRev[j]+1) dpRev[i]=dpRev[j]+1;
			}	
		}
	}
	int ans=0;
	for(int i=1; i<=N; i++){
		if(dp[i]==1) continue;
		ans=max(ans, dp[i]+dpRev[i]-1);
	}
	if(N!=0&&ans==0) ans=1;
	cout << ans;
}
//LIS (Bitonic 문제) 
//주의해야할점 : 1) 롤러코스터는 내려가는게없으면 하이라이트가 없는것
// 2) 하이라이트가 없으면 가장 큰 기둥만 남기기에 답은 1
