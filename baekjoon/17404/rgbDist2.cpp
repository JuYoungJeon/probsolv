#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_VAL 1000001

int dp[1001][3];
int arr[1001][3];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	memset(arr, 0, sizeof(arr));
	memset(dp, 0, sizeof(dp));
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<n; i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	int ans =MAX_VAL;
	for(int j=0; j<3; j++){
		for(int i=0; i<3; i++){
			if(j==i) dp[0][i]=arr[0][i];
			else dp[0][i]=MAX_VAL;
		}
		for(int i=1;i<n; i++){
			dp[i][0]=min(dp[i-1][1], dp[i-1][2])+arr[i][0];
			dp[i][1]=min(dp[i-1][0], dp[i-1][2])+arr[i][1];
			dp[i][2]=min(dp[i-1][0], dp[i-1][1])+arr[i][2];
		}
		for(int i=0;i<3; i++){
			if(j==i) continue;
			ans = min(ans, dp[n-1][i]);
		}
	}

	cout << ans;
}
