#include<cstdio>
#include<tuple>
#include<queue>
using namespace std;
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};

int visited[2][1001][1001];
int map[1001][1001];
queue<tuple<int, int, int> > q;

int bfs(int n, int m, int y, int x){
	q.push(make_tuple(0, y, x));
	visited[0][y][x]=1;
	while(!q.empty()){
		tuple<int, int, int> next=q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int ny=get<1>(next)+dir[i][0];
			int nx=get<2>(next)+dir[i][1];
			if(ny<1||ny>n|| nx<1 || nx>m) continue;
			if(map[ny][nx]==0){
				if(!visited[get<0>(next)][ny][nx]||visited[get<0>(next)][ny][nx]>visited[get<0>(next)][get<1>(next)][get<2>(next)]+1){
					visited[get<0>(next)][ny][nx]=visited[get<0>(next)][get<1>(next)][get<2>(next)]+1;
					q.push(make_tuple(get<0>(next),ny, nx));
				}
			}else{
				if(get<0>(next)==0){
					if(!visited[1][ny][nx]||visited[1][ny][nx]>visited[get<0>(next)][get<1>(next)][get<2>(next)]+1){
						visited[1][ny][nx]=visited[get<0>(next)][get<1>(next)][get<2>(next)]+1;
						q.push(make_tuple(1, ny, nx));
					}
				}
			}
		}
	}
	if(!visited[0][n][m]&&!visited[1][n][m]) return -1;
	if(!visited[0][n][m]) return visited[1][n][m];
	if(!visited[1][n][m]) return visited[0][n][m];
	return min(visited[0][n][m],visited[1][n][m]);
}
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++)
			scanf("%1d", &map[i][j]);
	}

	int ans=bfs(n, m, 1, 1);
	printf("%d", ans);
}
