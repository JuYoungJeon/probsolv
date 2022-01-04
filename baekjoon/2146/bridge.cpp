#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int dir[4][2]={{1,0}, {-1, 0}, {0, -1}, {0, 1}};
int N;
int map[100][100];
int visited[100][100];

void identifyIslands(int y, int x, int id){
	queue<pair<int, int>> q;
	q.push({y, x});
	map[y][x]=id;
	visited[y][x]=1;
	while(!q.empty()){
		pair<int, int> curr=q.front();
		q.pop();
		for(int i=0;i<4; i++){
			int ny=curr.first+dir[i][0];
			int nx=curr.second+dir[i][1];
			if(ny<0||nx<0||ny>=N||nx>=N) continue;
			if(!map[ny][nx]||visited[ny][nx]) continue;
			visited[ny][nx]=1;
			map[ny][nx]=id;
			q.push({ny, nx});
		}
	}
}

int getMinDist(int y, int x){
	queue<pair<int, int>> q;
	q.push({y, x});
	int minval=N*N;
	memset(visited, 0, sizeof(visited));
	while(!q.empty()){
		pair<int, int> curr=q.front();
		q.pop();
		for(int i=0;i<4; i++){
			int ny = curr.first+dir[i][0];
			int nx = curr.second+dir[i][1];
			if(ny<0||nx<0||ny>=N||nx>=N) continue;
			if(map[ny][nx]==map[y][x]||visited[ny][nx])continue;
			visited[ny][nx]=visited[curr.first][curr.second]+1;
			if(map[ny][nx]>1) {
				return visited[ny][nx]-1;
			}
			q.push({ny, nx});
		}
	}
	return minval;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			cin >> map[i][j];
		}
	}
	memset(visited, 0, sizeof(visited));
	int islandId=2;
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			if(visited[i][j] || !map[i][j]) continue;
			identifyIslands(i, j, islandId);
			islandId++;
		}
	}
	int ans=N*N;
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			if(map[i][j]==0) continue;
			ans=min(ans, getMinDist(i, j));
		}
	}
	cout << ans;
}
