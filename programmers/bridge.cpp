#include <string>
#include <vector>
#include<iostream>
#include <algorithm>
using namespace std;
int dist[50001];

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(0); rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    int s=0; int e=distance;
    while(s<=e){
        int mid = (s+e)/2;
        int cnt=0; int prev =0;
        for(int i=1;i<rocks.size(); i++){
            if(mid>rocks[i]-prev)cnt+=1;
            else prev=rocks[i];
        }
        if(cnt<=n){
            answer=max(answer, mid);
            s=mid+1;
        }else e=mid-1;
    }
    return answer;
}
