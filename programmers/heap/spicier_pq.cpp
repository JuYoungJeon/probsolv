#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> >pq;
    for(int s: scoville){
        pq.push(s);
    }
    while(pq.top()<K){
        if(pq.size()==1){
            answer=-1;
            break;
        }
        int newSc=pq.top();
        pq.pop();
        newSc+=pq.top()*2;
        pq.pop();
        pq.push(newSc);
        answer+=1;
        
    }
    return answer;
}
