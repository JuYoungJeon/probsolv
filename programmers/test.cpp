#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int first[5]={1,2,3,4,5};
int second[8]={2,1,2,3,2,4,2,5};
int third[10]={3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers){
    vector<int> scores(3);
    vector<int> ans;
    int maxScore=0;
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==first[i%5]) scores[0]+=1;
        if(answers[i]==second[i%8]) scores[1]+=1;
        if(answers[i]==third[i%10]) scores[2]+=1;
        maxScore=max(maxScore, max(scores[0], max(scores[1], scores[2])));
    }
    for (int i=0; i<3; i++)
        if(scores[i]==maxScore) ans.push_back(i+1);
    return ans;
}
