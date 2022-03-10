#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int dir[4][2]={{1,0}, {-1, 0}, {0, -1}, {0, 1}};

int N, M;
int map[300][300];
int visited[300][300];

void bfs(int y, int x){
	queue<pair<int, int>> q;
	visited[y][x]=1;
	q.push({y, x});
	while(!q.empty()){
		pair<int, int> c=q.front();
		q.pop();
		for(int i=0;i<4; i++){
			int ny = c.first+dir[i][0];
			int nx = c.second+dir[i][1];
			if(ny<0||ny>=N||nx<0||nx>=M) continue;
			if(visited[ny][nx]) continue;
			if(!map[ny][nx]) map[c.first][c.second]-=1;
			else{
				q.push({ny, nx});
				visited[ny][nx]=1;
			}
			if(map[c.first][c.second]<0) map[c.first][c.second]=0;
		}
	}
}

void bfsCheck(int y, int x){
	queue<pair<int, int>> q;
	q.push({y, x});
	visited[y][x]=1;
	while(!q.empty()){
		pair<int, int> c = q.front();
		q.pop();
		for(int i=0;i<4; i++){
			int ny = c.first+dir[i][0];
			int nx = c.second+dir[i][1];
			if(ny<0||ny>=N||nx<0||nx>=M) continue;
			if(visited[ny][nx]||!map[ny][nx]) continue;
			visited[ny][nx]=1;
			q.push({ny, nx});
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for(int i=0;i<N; i++){
		for(int j=0;j<M; j++){
			cin >> map[i][j];
		}
	}
	int numIceburg=0;
	int ans=0;
	while(1){
		numIceburg=0;
		memset(visited, 0, sizeof(visited));
		for(int i=0;i<N; i++){
			for(int j=0;j<M; j++){
				if(!visited[i][j]&&map[i][j]){
					numIceburg++;
					bfsCheck(i,j);
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		for(int i=0;i<N; i++){
			for(int j=0;j<M; j++){
				if(!visited[i][j]&&map[i][j]){
					bfs(i, j);
				}
			}
		}
		if(numIceburg==0){ ans=0; break; }
		if(numIceburg!=1) break;
		ans++;
	}
	cout << ans;
}
