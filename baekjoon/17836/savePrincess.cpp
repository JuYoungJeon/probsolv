#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define pii pair<int, int>
#define INF 10001

int dir[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int map[100][100];
int visited[100][100];

int bfs(int N, int M, pii dest){
	queue<pii> q;
	memset(visited, -1, sizeof(visited));
	q.push({0, 0});
	visited[0][0]=0;
	while(!q.empty()){
		pii curr = q.front();
		q.pop();
		for(int i=0;i<4; i++){
			int ny = curr.first+dir[i][0];
			int nx = curr.second+dir[i][1];
			if(ny<0||nx<0||ny>=N||nx>=M) continue;
			if(map[ny][nx]==1) continue;
			if(visited[ny][nx]>-1)continue;
			visited[ny][nx]=visited[curr.first][curr.second]+1;			
			q.push({ny, nx});
		}
	}
	if(visited[dest.first][dest.second]==-1) return INF;
	else return visited[dest.first][dest.second];
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, T;
	cin >> N >> M >> T;
	int swy, swx;
	for(int i=0; i<N; i++){
		for(int j=0;j<M; j++){
			cin >> map[i][j];
			if(map[i][j]==2){
				swy=i;
				swx=j;
			}
		}
	}
	int ans = min(bfs(N, M, {N-1, M-1}), bfs(N, M, {swy, swx})+N-swy-1+M-swx-1);
	if(ans>T) cout << "Fail\n";
	else cout << ans;
}
