#include <string>
#include <vector>
#include <iostream>

using namespace std;

int win[46];

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int minAns=0;
    int maxAns=0;
    for(int i=0;i<win_nums.size(); i++){
        win[win_nums[i]]=1;
    }
    for(int i=0;i<lottos.size(); i++){
        if(lottos[i]==0) {
            maxAns+=1;
        }
        if(win[lottos[i]]){
            maxAns+=1;
            minAns+=1;
        }
    }
    if(maxAns<2) answer.push_back(6);
    else answer.push_back(6-maxAns+1);
    if(minAns<2) answer.push_back(6);
    else answer.push_back(6-minAns+1);
    return answer;
}
