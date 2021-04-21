#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
vector<int> dp[20001];

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n=(int)A.size();
	dp[0]=vector<int>();
	dp[0].push_back(0);
    for(int i=1; i<=n; i++){
        dp[i]=vector<int> ();
        cout << dp[i-1].size()<<'\n';
        for(int j=0; j<(int)dp[i-1].size(); j++){
            dp[i].push_back(dp[i-1][j]+A[i-1]);
            dp[i].push_back(dp[i-1][j]*-1+A[i-1]);
        }
    }
    int minVal=100*20000;
    for(int i=0; i<(int)dp[n].size(); i++){
        minVal=min(minVal, abs(dp[n][i]));
    }
    return minVal;
}


int main(void){
	vector<int> A{3, 1};
	cout << solution(A);
}
