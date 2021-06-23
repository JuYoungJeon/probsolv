#include<cstdio>
#include<vector>
using namespace std;
vector<int> dp;
vector<int> res;
void getMinNum(int n, int minV){
	if (n<1||dp[n]<=minV) return;
	dp[n]=minV;
	if(n%3==0) getMinNum(n/3, minV+1);
	if(n%2==0) getMinNum(n/2, minV+1);
	getMinNum(n-1, minV+1);
}
void getRes(int n, int idx){
	if(idx>n) return;
	res.push_back(idx);
	if(idx*3<=n&&dp[idx*3]==dp[idx]-1) getRes(n, idx*3);
	else if(idx*2<=n && dp[idx*2]==dp[idx]-1) getRes(n, idx*2);
	else getRes(n, idx+1);
}
int main(void){
	int n;
	scanf("%d", &n);
	for(int i=0; i<=n; i++) dp.push_back(n);
	getMinNum(n, 0);
	printf("%d\n", dp[1]);
	getRes(n, 1);
	for(int i=res.size()-1; i>=0; i--) printf("%d ", res[i]); 
}
