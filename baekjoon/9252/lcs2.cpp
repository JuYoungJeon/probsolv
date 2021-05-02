#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1001][1001];

int main(void){
	string a, b;
	cin >> a>>b;
	memset(dp, 0, sizeof(dp));
	for(int i=1;i<=a.size(); i++){
		for(int j=1; j<=b.size(); j++){
			if(a[i-1]!=b[j-1])dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			else dp[i][j]=dp[i-1][j-1]+1;
		}
	}
	//backtrack largest substring
	string lss="";
	int i=a.size(), j=b.size();
	while(dp[i][j]>0){
		if(dp[i-1][j]==dp[i][j])i--;
		else if(dp[i][j]==dp[i][j-1]) j--;
		else if(dp[i][j]>dp[i-1][j-1]){lss=a[i-1]+lss;i--; j--;}
	}
	cout << dp[a.size()][b.size()] <<'\n'<< lss;
}
//Note:string index 와 dp index는 다름
