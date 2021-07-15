#include<iostream>
#include<algorithm>
#define INF 1000000
using namespace std;
int dp[202][202][3];
int arr[202][2];

int getDP(int k, int n, int idx){
    if(dp[k][n][idx]) return dp[k][n][idx];
    if(n<0||k<0) return 0;
    if(k>n) return dp[k][n][idx]=INF;
    if(idx>1) {
        if(k>=n) return dp[k][n][idx]=INF;
        dp[k][n][idx]= min(getDP(k, n-1, 1), getDP(k, n-1, 2));
        dp[k][n][idx]= min(getDP(k, n-1, 0), dp[k][n][idx]);
    }else dp[k][n][idx]=min(getDP(k-1, n-1, 2)+arr[n][idx], getDP(k-1, n-1, idx)+arr[n][idx]);
    return dp[k][n][idx];
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    int sum=0;
    for(int i=0;i<=N; i++){
        cin >> arr[i][0] >> arr[i][1];
        sum+=arr[i][0]; sum+=arr[i][1];
    }
    for(int i=0;i<3; i++) getDP(K-1, N-1, i);
    int minOut = min(dp[K-1][N-1][0], dp[K-1][N-1][1]);
    minOut = min(minOut, dp[K-1][N-1][2]);
    if(K==0) minOut=0;
    cout << sum-minOut;
}
//scanf printf 하면 틀림...왜지...???????
