#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> topord[32001];
int innode[32001];

bool cmp(int a, int b) { return a<b;}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m; i++){
        int a, b;
        cin >> a >> b;
        topord[a].push_back(b);
        innode[b]+=1;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1; i<=n; i++){
        if(innode[i]==0) pq.push(i);
    }
    while(!pq.empty()){
        int curr = pq.top();
        pq.pop();
        cout << curr<<' ';
        for(auto& next : topord[curr]){
            innode[next]-=1;
            if(innode[next]==0) pq.push(next);
        }
    }
}
