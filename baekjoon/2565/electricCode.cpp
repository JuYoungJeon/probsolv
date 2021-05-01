#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int dp[101][2];
int c[101];
vector<pair<int, int> > codes;
bool cmpCode(pair<int, int> a, pair<int,int> b){
	return a.first<b.first;
}
int main(void){
	int n;
	scanf("%d", &n);
	memset(dp, 0, sizeof(dp));
	memset(c, 0, sizeof(c));
	for(int i=0; i<n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		codes.push_back(make_pair(a, b));
	}
	sort(codes.begin(), codes.end(), cmpCode);
	for(int i=0; i<n; i++){
		c[i]=codes[i].second;	
	}

	dp[0][0]=0;
	dp[0][1]=1;
	for(int i=1; i<n; i++){
		dp[i][0]=max(dp[i-1][0], dp[i-1][1]);
		int p=0;
		for(int j=i-1; j>=0; j--)
			if(c[i]>c[j])p=max(p, dp[j][1]);
		dp[i][1]=p+1;
	}
	printf("%d", n-max(dp[n-1][0],dp[n-1][1]));
}
//Note: 가장 긴 수열 찾기 문제로 치환 
//1. 출발선을 기준으로 sorting하여 도착 선을 나열
//2. 도착 선의 가장 긴증가하는 부분찾기(x)
//3. n-x출력
