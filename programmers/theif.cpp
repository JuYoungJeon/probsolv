#include <string>
#include <vector>
#include <cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int dp[1000001]; memset(dp, 0, sizeof(dp));
    int dp2[1000001]; memset(dp2, 0, sizeof(dp2));
    dp[0]=money[0]; dp[1]=max(money[0], money[1]);
    for(int i=2;i<money.size()-1; i++){
        dp[i]=max(dp[i-1], dp[i-2]+money[i]);
    }
    dp2[1]=money[1];
    for(int i=2; i<money.size(); i++){
        dp2[i]=max(dp2[i-1], dp2[i-2]+money[i]);
    }
    answer = max(dp[money.size()-2], dp2[money.size()-1]);
    return answer;
}
