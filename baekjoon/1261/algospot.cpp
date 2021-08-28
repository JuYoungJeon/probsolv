#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
#define pii pair<int, int>
int map[100][100];
int visited[100][100];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

void bfs(int y, int x){
	queue<pii> q;
	q.push({0,0});
	visited[0][0]=0;
	while(!q.empty()){
		pii curr = q.front();
		int cy = curr.first;
		int cx = curr.second;
		q.pop();
		for(int i=0;i<4; i++){
			int ny = cy+dir[i][0];
			int nx = cx+dir[i][1];
			if(ny>y||ny<0||nx>x||nx<0) continue;
			if(map[ny][nx]==1){
				if(visited[ny][nx]==-1||visited[ny][nx]>visited[cy][cx]+1){
					visited[ny][nx]=visited[cy][cx]+1;
					q.push({ny,nx});
				}

			}else{
				if(visited[ny][nx]==-1||visited[ny][nx]>visited[cy][cx]){
					visited[ny][nx]=visited[cy][cx];
					q.push({ny,nx});
				}
			}
		}
	}
}

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	memset(visited, -1, sizeof(visited));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(m-1, n-1);
	printf("%d", visited[m-1][n-1]);
}
