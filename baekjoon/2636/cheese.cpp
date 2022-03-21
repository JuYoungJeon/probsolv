#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};

int map[100][100];
int visited[100][100];

int bfs(int N, int M, int total){
	queue<pair<int, int>> q;
	visited[0][0]=1;
	q.push({0, 0});
	int cnt =0;
	while(!q.empty()){
		pair<int, int> c = q.front();
		q.pop();
		for(int i=0;i<4; i++){
			int ny = c.first+dir[i][0];
			int nx = c.second+dir[i][1];
			if(ny<0||ny>=N||nx<0||nx>=M) continue;
			if(visited[ny][nx]) continue;
			if(map[ny][nx]) {
				cnt+=1;
				map[ny][nx]=0;
			}else q.push({ny, nx});
			visited[ny][nx]=1;
		}
	}
	return total-cnt;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	int ans=0, left=0;
	for(int i=0;i<N; i++){
		for(int j=0;j<M;j++){
			cin >> map[i][j];
			if(map[i][j]) left+=1;
		}
	}
	while(left>0){
		memset(visited, 0, sizeof(visited));
		int ret = bfs(N, M, left);
		ans++;
		if(!ret) break;
		left = ret;
	}
	cout << ans <<'\n' << left;
}
