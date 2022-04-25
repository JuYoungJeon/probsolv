#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

const int dir[4][2]={{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int map[20][20];
int cusmap[20][20];
int dist[20][20];
pair<pair<int, int>, pair<int, int>> s2d[405];
int sy, sx, fuel;

void bfs(int N){
	memset(dist, -1, sizeof(dist));
	queue<pair<int,int>> q;
	dist[sy][sx]=0;
	bool found = false;
	int dy, dx;
	dy=-1, dx=-1;
	if(cusmap[sy][sx]>0) {
		found = true;
		dy = s2d[cusmap[sy][sx]].second.first;
		dx = s2d[cusmap[sy][sx]].second.second;
		cusmap[sy][sx]=0;
	}else{
		q.push({sy, sx});
	}
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for(int i=0;i<4; i++){
			int ny = cy+dir[i][0];
			int nx = cx+dir[i][1];
			if(ny<0||nx<0||ny>=N||nx>=N) continue;
			if(dist[ny][nx]>-1) continue;
			if(map[ny][nx]==1) continue;
			dist[ny][nx]=dist[cy][cx]+1;
			if(cusmap[ny][nx]>0){
				if((dy==-1&&dx==-1)||(dist[sy][sx]==dist[ny][nx]&&(sy>ny||(sy==ny&&sx>nx)))){
					dy = s2d[cusmap[ny][nx]].second.first;
					dx = s2d[cusmap[ny][nx]].second.second;
					sy = s2d[cusmap[ny][nx]].first.first;
					sx = s2d[cusmap[ny][nx]].first.second;
					found =true;
				}
			}
			q.push({ny, nx});
		}
	}
	if(!found || fuel<dist[sy][sx]) fuel=-1;
	else fuel -=(dist[sy][sx]);
	cusmap[sy][sx]=0;
	if(fuel==-1) return;
	while(!q.empty()) q.pop();
	memset(dist, -1, sizeof(dist));
	q.push({sy, sx});
	dist[sy][sx]=0;
	found = false;
	while(!q.empty()&&!found){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for(int i=0;i<4; i++){
			int ny = cy+dir[i][0];
			int nx = cx+dir[i][1];
			if(ny<0||nx<0||ny>=N||nx>=N) continue;
			if(dist[ny][nx]>-1) continue;
			if(map[ny][nx]==1) continue;
			dist[ny][nx]=dist[cy][cx]+1;
			if(ny==dy&& nx==dx) {
				if(fuel<dist[ny][nx]) {
					found=true;
					fuel=-1;
					break;
				}
				fuel+=(dist[ny][nx]);
				sy = dy;
				sx = dx;
				found = true;
				break;
			}
			q.push({ny, nx});
		}
		if(found) break;
	}
	if(!found) fuel =-1;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M >> fuel;

	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			cin >> map[i][j];
		}
	}
	cin >> sy >> sx;
	sy-=1; sx-=1;
	for(int i=1;i<=M; i++){
		int msy, msx, mdy, mdx;
		cin >> msy >> msx>>mdy>>mdx;
		s2d[i]={{msy-1, msx-1}, {mdy-1, mdx-1}};
		cusmap[msy-1][msx-1]=i;
	}
	for(int i=0;i<M; i++){
		bfs(N);
		if(fuel==-1) break;
	}
	cout << fuel;
}
