#include<iostream>
#include<queue>

#define INF 2501

using namespace std;

int N, M;
int dir[4][2]={{1,0}, {0, 1}, {-1, 0}, {0, -1}};
char map[50][50];
int garb[50][50][2];

struct node{
    int g, gn;
    pair<int, int> l;
};

struct compare{
    bool operator()(node a, node b){
        if(a.g!=b.g) return a.g>b.g;
        return a.gn>b.gn;
    }
};

int checkGarbNear(pair<int, int> n){
    for(int i=0;i<4; i++){
        int ny = n.first+dir[i][0];
        int nx = n.second+dir[i][1];
        if(ny<0||ny>=N||nx<0||nx>=M) continue;
        if(map[ny][nx]=='g')
            return 1;
    }
    return 0;
}

void bfs(pair<int, int> s, pair<int, int> e){
    priority_queue<node, vector<node>, compare> pq;
    node sn = {0, 0, s};
    garb[s.first][s.second][0]=0;
    garb[s.first][s.second][1]=0;
    pq.push(sn);
    while(!pq.empty()){
        node c = pq.top();
        pq.pop();
        if(c.g>garb[c.l.first][c.l.second][0]) continue;
        if(c.g==garb[c.l.first][c.l.second][0]&&c.gn>garb[c.l.first][c.l.second][1]) continue;
        for(int i=0;i<4; i++){
            int ny = c.l.first+dir[i][0];
            int nx = c.l.second+dir[i][1];
            if(ny<0||ny>=N||nx<0||nx>=M)continue;
            if((garb[ny][nx][0]>c.g+(map[ny][nx]=='g'))||(garb[ny][nx][0]==c.g+(map[ny][nx]=='g')&&garb[ny][nx][1]>c.gn+checkGarbNear({ny, nx}))){
				garb[ny][nx][0]=c.g;
				garb[ny][nx][1]=c.gn;
				if(map[ny][nx]=='g') garb[ny][nx][0]=c.g+1;
                else if (checkGarbNear({ny, nx})) garb[ny][nx][1]=c.gn+1;
                node n = {garb[ny][nx][0], garb[ny][nx][1], make_pair(ny, nx)};
                pq.push(n);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    pair<int, int> s, e;
    for(int i=0;i<N; i++){
        for(int j=0;j<M; j++){
            cin >> map[i][j];
            garb[i][j][0]=INF;
            garb[i][j][1]=INF;
            if(map[i][j]=='S') s = make_pair(i, j);
            if(map[i][j]=='F') e = make_pair(i, j);
        }
    }
    bfs(s, e);
    cout << garb[e.first][e.second][0]<<' '<< garb[e.first][e.second][1]-checkGarbNear(e);
}

