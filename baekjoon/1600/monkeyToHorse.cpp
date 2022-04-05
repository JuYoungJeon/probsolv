#include<iostream>
#include<queue>
#include<vector>
#include<tuple>

using namespace std;

int dist[200][200][31];
int map[200][200];
int dir[12][2]={{2, -1}, {-2, -1}, {2, 1}, {-2, 1}, {1, -2}, {-1, -2}, {-1, 2}, {1, 2}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int K, int H, int W){
	queue<tuple<int, int, int>> q;
	q.push({0, 0, K});
	dist[0][0][K]=0;
	while(!q.empty()){
		tuple<int, int, int> t =q.front();
		pair<int, int> c = {get<0>(t), get<1>(t)};
		int kl = get<2>(t);
		q.pop();
		for(int i=0;i<8; i++){
			if(i< 8&& kl==0) break;
			int ny = c.first+dir[i][0];
			int nx = c.second+dir[i][1];
			if(ny<0||ny>=H|| nx<0||nx>=W) continue;
			if(map[ny][nx]==1) continue;
			if(dist[ny][nx][kl-1]<=dist[c.first][c.second][kl]+1) continue;
			dist[ny][nx][kl-1]=dist[c.first][c.second][kl]+1;
			q.push({ny, nx, kl-1});
		}
		for(int i=8;i<12; i++){
			int ny = c.first+dir[i][0];
			int nx = c.second+dir[i][1];
			if(ny<0||ny>=H|| nx<0||nx>=W) continue;
			if(map[ny][nx]==1) continue;
			if(dist[ny][nx][kl]<=dist[c.first][c.second][kl]+1) continue;
			dist[ny][nx][kl]=dist[c.first][c.second][kl]+1;
			q.push({ny, nx, kl});
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, W, H;
	cin >> K >> W >>H;
	for(int i=0;i<H; i++){
		for(int j=0;j<W; j++){
			cin >> map[i][j];
			for(int k=0;k<=K; k++)dist[i][j][k]=H*W;
		}
	}
	bfs(K, H, W);
	int ans = H*W;
	for(int i=0;i<=K; i++) ans=min(ans, dist[H-1][W-1][i]);
	if(ans!=H*W) cout << ans;
	else cout << -1;
}
