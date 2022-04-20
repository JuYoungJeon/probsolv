#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;

int dir[4][2]={{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int map[64][64];
int visited[64][64];

void firestorm(int N, int s){
	int unit = pow(2, s);
	int newmap[64][64];
	memset(newmap, 0, sizeof(newmap));
	for(int i=0;i<(N/unit)*(N/unit); i++){
		for(int y=i/(N/unit)*unit; y<i/(N/unit)*unit+unit; y++){
			for(int x= (i*unit)%N; x<(i*unit)%N+unit; x++){
				newmap[(i/(N/unit)*unit)+x-(i*unit)%N][(i*unit)%N+unit-y-1+i/(N/unit)*unit]=map[y][x];
			}
		}
	}
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			int cnt=0;
			for(int d=0; d<4; d++){
				int ny = i+dir[d][0];
				int nx = j+dir[d][1];
				if(ny<0||nx<0||ny>=N||nx>=N) continue;
				if(newmap[ny][nx]>0) cnt++;
			}
			if(cnt>=3) map[i][j]=newmap[i][j];
			else map[i][j]=max(0, newmap[i][j]-1);
		}
	}
}
int bfs(int i, int j, int N){
	queue<pair<int, int>> q;
	int cnt =1;
	visited[i][j]=1;
	q.push({i, j});
	while(!q.empty()){
		pair<int, int> c = q.front();
		q.pop();
		for(int d=0;d<4; d++){
			int ny = c.first+dir[d][0];
			int nx = c.second+dir[d][1];
			if(ny <0 || nx<0|| ny>=N || nx>=N) continue;
			if(visited[ny][nx]) continue;
			if(map[ny][nx]==0) continue;
			visited[ny][nx]=1;
			cnt+=1;
			q.push({ny, nx});
		}
	}
	return cnt;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, Q;
	int ans=0, lar=0;
	cin >> N >> Q;
	for(int i=0;i<pow(2,N); i++){
		for(int j=0;j<pow(2,N); j++){
			cin >> map[i][j];
		}
	}
	for(int i=0;i<Q; i++){
		int t;
		cin >> t;
		firestorm(pow(2, N), t);
	}
	for(int i=0; i<pow(2,N); i++){
		for(int j=0;j<pow(2,N); j++){
			ans+=map[i][j];
		}
	}
	for(int i=0;i<pow(2, N); i++){
		for(int j=0;j<pow(2, N); j++){
			if(map[i][j]!=0&&!visited[i][j]) lar=max(lar, bfs(i, j, pow(2, N)));
		}
	}
	cout << ans << '\n'<< lar;
}
