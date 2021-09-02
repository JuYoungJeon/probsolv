#include <string>
#include <vector>

using namespace std;

int visited[201]={0};
vector<int> conn[201];
bool dfs(int n, int i){
    if(visited[i]) return false;
    visited[i]=1;
    for(auto& a:conn[i]){
        dfs(n, a);
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n; i++){
        for(int j=0;j<n; j++){
            if(computers[i][j]==1){
                conn[i].push_back(j);
                conn[j].push_back(i);
            }
        }
    }
    for(int i=0;i<n; i++)
        if(dfs(n, i)) answer+=1;

    return answer;
}
