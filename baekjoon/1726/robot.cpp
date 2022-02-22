#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

//east, south, west, north
int dir[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int map[100][100];
int visited[100][100][4];
struct loc{
	int y, x, d;
};
int N, M;

int setDir(int d){
	if(d==1) return 0;
	if(d==2) return 2;
	if(d==3) return 1;
	if(d==4) return 3;
}

void bfs(loc rob){
	queue<loc> q;
	q.push(rob);
	visited[rob.y][rob.x][rob.d]=0;
	while(!q.empty()){
		loc c = q.front();
		q.pop();
		int rd= (c.d+1)%4;
		int ld = (c.d-1)<0? 3:c.d-1;
		if(visited[c.y][c.x][rd]==-1||visited[c.y][c.x][rd]>visited[c.y][c.x][c.d]){
			visited[c.y][c.x][rd]=visited[c.y][c.x][c.d]+1;
			loc n = {c.y, c.x, rd};
			q.push(n);
		}
		if(visited[c.y][c.x][ld]==-1||visited[c.y][c.x][ld]>visited[c.y][c.x][c.d]){
			visited[c.y][c.x][ld]=visited[c.y][c.x][c.d]+1;
			loc n={c.y, c.x, ld};
			q.push(n);
		}
		for(int i=1; i<4; i++){
			int ny=c.y+dir[c.d][0]*i;
			int nx=c.x+dir[c.d][1]*i;
			if(ny<0||ny>=N||nx<0||nx>=M) continue;
			if(map[ny][nx]==1) break;
			if(visited[ny][nx][c.d]!=-1) continue;
			visited[ny][nx][c.d]=visited[c.y][c.x][c.d]+1;
			loc n = {ny, nx, c.d};
			q.push(n);
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(visited, -1, sizeof(visited));

	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0;j<M; j++){
			cin >> map[i][j];
		}
	}
	loc rob, dest;
	cin>> rob.y >> rob.x >> rob.d;
	cin >> dest.y >> dest.x >> dest.d;

	rob.y-=1; 
	rob.x-=1;
	rob.d=setDir(rob.d);
	dest.y-=1;
	dest.x-=1;
	dest.d=setDir(dest.d);

	bfs(rob);
	cout << visited[dest.y][dest.x][dest.d];
}
