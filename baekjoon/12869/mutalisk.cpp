#include<iostream>
#include<cstring>

using namespace std;

int dp[61][61][61];
int m[3];

int getMinTime(int a, int b, int c){
	if(a < 0) return getMinTime(0, b, c);
	if(b < 0) return getMinTime(a, 0, c);
	if(c < 0) return getMinTime(a, b, 0);
	if(a==0&&b==0&&c==0) return 0;
	if(dp[a][b][c]>-1) return dp[a][b][c];
	int ret =60;
	ret = min(ret, getMinTime(a-9, b-3, c-1)+1);
	ret = min(ret, getMinTime(a-9, b-1, c-3)+1);
	ret = min(ret, getMinTime(a-3, b-9, c-1)+1);
	ret = min(ret, getMinTime(a-3, b-1, c-9)+1);
	ret = min(ret, getMinTime(a-1, b-3, c-9)+1);
	ret = min(ret, getMinTime(a-1, b-9, c-3)+1);
	dp[a][b][c]=ret;
	return dp[a][b][c];
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	memset(dp, -1, sizeof(dp));
	for(int i=0;i<N; i++) cin >> m[i];

	getMinTime(m[0], m[1], m[2]);
	cout << dp[m[0]][m[1]][m[2]];
	
}
