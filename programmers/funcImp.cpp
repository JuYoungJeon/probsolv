#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> leftD;
    for(int i=0; i<progresses.size(); i++){
        int days=(100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i]>0) days+=1;
        leftD.push(days);
    }
    int numRelease=0;
    while(!leftD.empty()){
        int first=leftD.front();
        numRelease+=1;
        leftD.pop();
        while(first>=leftD.front()&&!leftD.empty()){
            numRelease+=1;
            leftD.pop();
        }
        answer.push_back(numRelease);
        numRelease=0;
    }
    return answer;
}
