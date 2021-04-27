#include <string>
#include <iostream>
#include <vector>

using namespace std;


vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=1; i<=prices.size(); i++){
        int found=i;
        while(found < prices.size() && prices[i-1]<=prices[found]){
            found+=1;
        }
        if(found == prices.size())found-=1;
        answer.push_back(found-i+1);
    }
    return answer;
    
}
