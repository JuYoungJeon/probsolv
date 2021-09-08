#include <string>
#include<queue>
#include <vector>
#include<iostream>

using namespace std;
#define INF 98765432
int dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    for(int i=1;i<=n; i++){
        for(int j=1; j<=n; j++){
        	dist[i][j]=INF;
        }
        dist[i][i]=0;
    }    
    for(auto& f: fares){
        dist[f[0]][f[1]]=f[2];
        dist[f[1]][f[0]]=f[2];
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][k]==INF||dist[k][j]==INF) continue;
                if(dist[i][j]>dist[i][k]+dist[k][j]) dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(dist[s][i]==INF||dist[i][a]==INF||dist[i][b]==INF) continue;
        answer=min(answer, dist[s][i]+dist[i][a]+dist[i][b]);
    }
    return answer;
}
