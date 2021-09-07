#include <string>
#include <vector>
#include<iostream>
#include <queue>
#include <algorithm>
using namespace std;
bool cmp(vector<int> a, vector<int>b){ return a[0]<b[0];}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(routes.begin(), routes.end(), cmp);
    int maxval=routes[0][1]; answer+=1;
    for(int i=1;i<routes.size(); i++){
        if(maxval<routes[i][0]){answer+=1; maxval=routes[i][1];}
        else if(maxval>routes[i][1]){ maxval=routes[i][1];}
    }
    return answer;
}
