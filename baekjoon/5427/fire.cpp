#include<cstdio>
#include<utility>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef pair<int, int> pii;

char map[1001][1001];
int visited[1001][1001];
queue<pii> fire;
queue<pii> loc;
int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};

void bfs(int h, int w, int sy, int sx){
	while(!fire.empty()){
		pii f = fire.front();
		fire.pop();
		for(int i=0;i<4; i++){
			int dy=f.first+dir[i][0]; 
			int dx=f.second+dir[i][1];
			if(dy<0||dy>=h||dx<0||dx>=w) continue;
			if(map[dy][dx]=='#'||(visited[dy][dx]<0&&visited[dy][dx]>=visited[f.first][f.second]-1)) continue;
			visited[dy][dx]=visited[f.first][f.second]-1;
			fire.push({dy, dx});
		}
	}
	visited[sy][sx]=1;
	while(!loc.empty()){
		pii l =loc.front();
		loc.pop();
		for(int i=0;i<4; i++){
			int dy=l.first+dir[i][0];
			int dx=l.second+dir[i][1];
			if(dy<0||dy>=h||dx<0||dx>=w) continue;
			if(map[dy][dx]=='#'||(abs(visited[dy][dx])<=visited[l.first][l.second]+1&&visited[dy][dx]!=0)) continue;
			visited[dy][dx]=visited[l.first][l.second]+1;
			loc.push({dy, dx});
		}
	}
}

int main(void){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		memset(visited, 0, sizeof(visited));
		int w, h;
		scanf("%d %d", &w, &h);
		int sy, sx;
		getchar();
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				scanf("%c", &map[i][j]);
				if(map[i][j]=='@') {loc.push({i, j});sy=i;sx=j;}
				if(map[i][j]=='*') {fire.push({i,j});visited[i][j]=-1;}
				if(map[i][j]=='#') visited[i][j]=w*h+1;
			}
			getchar();
		}
		bfs(h, w, sy, sx);
		int ans=h*w+1;
		for(int i=0;i<h;i++) {
			if(visited[i][0]>0)
				ans=min(visited[i][0], ans);
			if(visited[i][w-1]>0)
				ans=min(visited[i][w-1], ans);
		}
		for(int i=0;i<w;i++){
			if(visited[0][i]>0)
				ans=min(visited[0][i], ans);
			if(visited[h-1][i]>0)
				ans=min(visited[h-1][i],ans);
		}
		if(ans==h*w+1) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);
	}
}
