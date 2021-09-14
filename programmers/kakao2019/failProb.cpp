#include <string>
#include<queue>
#include<iostream>
#include<cstring>
#include <vector>

using namespace std;

struct cmp{
    bool operator()(pair<double, int> a, pair<double, int> b){
        if(a.first==b.first){
            return a.second>b.second;
        }else return a.first<b.first;
    }
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    priority_queue<pair<double, int>, vector<pair<double, int>>, cmp> pq;
    int u2s[502];
    int cntUsers[502];
    memset(u2s, 0, sizeof(u2s));
    memset(cntUsers, 0, sizeof(cntUsers));
    for(int i=0;i<stages.size(); i++){
        u2s[stages[i]]+=1;
        
    }
    cntUsers[N+1] = u2s[N+1];
    for(int i=N;i>0; i--){
        cntUsers[i]=cntUsers[i+1]+u2s[i];
        if(cntUsers[i]==0) pq.push({0, i});
        else pq.push({u2s[i]*1.0/cntUsers[i], i});
    }
    while(!pq.empty()){
        answer.push_back(pq.top().second);
        pq.pop();
    }
    return answer;
}
