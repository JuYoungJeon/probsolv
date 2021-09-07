#include <string>
#include <vector>

using namespace std;
int win[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer=0;
    for(auto& r: results){
        win[r[0]][r[1]]=1;
    }
    for(int i=1;i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(win[j][i]&&win[i][k]) win[j][k]=1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        int cnt=0;
        for(int j=1; j<=n; j++){
        	if(win[i][j])cnt+=1;
        }
        for(int j=1; j<=n; j++){
            if(win[j][i]) cnt+=1;
        }
        if(cnt==n-1)answer+=1;
    }
    return answer;
}
