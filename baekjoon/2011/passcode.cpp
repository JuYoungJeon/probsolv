#include<iostream>
#include<string>

#define DIV 1000000

using namespace std;

int dp[5001];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string num;
	cin >> num;
	if(num[0]-'0'<=0||num[0]-'0'>10){
		cout << 0;
		return 0;
	}
	dp[0]=1;
	if(num.size()<2){
		cout << dp[0];
		return 0;
	}
	if(num[1]-'0'>0&&num[1]-'0'<10) dp[1]+=dp[0];
	if(stoi(num.substr(0, 2))>0&&stoi(num.substr(0,2))<27) dp[1]+=1;
	if(dp[1]==0) {
		cout << 0;
		return 0;
	}
	for(int i=2; i<num.size(); i++){
		if(num[i]-'0'>0&&num[i]-'0'<10) dp[i]=(dp[i]+dp[i-1])%DIV;
		if(num[i-1]-'0'>0&&stoi(num.substr(i-1,2))>0&&stoi(num.substr(i-1,2))<27) dp[i]=(dp[i]+dp[i-2])%DIV;
		if(dp[i]==0) {
			cout << 0;
			return 0; 
		}
	}
	cout <<dp[num.size()-1];
}
