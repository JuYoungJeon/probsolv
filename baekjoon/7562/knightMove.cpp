#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
int dir[8][2]={{2,1},{1,2},{2,-1},{1,-2},{-1,2},{-2,1},{-1,-2},{-2,-1}};
queue<pair<int, int> > q;
int visited[300][300];

int bfs(int l, int y, int x, int ty, int tx){
	q.push(make_pair(y, x));
	visited[y][x]=1;
	while(!q.empty()){
		pair<int,int> n=q.front();
		q.pop();
		for(int i=0;i<8; i++){
			int ny=n.first+dir[i][0];
			int nx=n.second+dir[i][1];
			if(ny<0||ny>l-1||nx<0||nx>l-1) continue;
			if(!visited[ny][nx]||visited[ny][nx]>visited[n.first][n.second]+1){
				visited[ny][nx]=visited[n.first][n.second]+1;
				q.push(make_pair(ny, nx));
			}
		}
	}
	return visited[ty][tx]-1;
}

int main(void){
	int tc;
	scanf("%d", &tc);
	for(int i=0;i<tc; i++){
		memset(visited, 0, sizeof(visited));
		int l;
		scanf("%d", &l);
		int y, x, ty, tx;
		scanf("%d %d", &y, &x);
		scanf("%d %d", &ty, &tx);
		printf("%d\n", bfs(l,y,x,ty,tx));
	}
}
//NOTE: move 할 direction 설정 확인
