#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
//Graph 개수 세기
int map[51][51];
int visited[51][51];
queue<pair<int, int> > q;
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
void bfs(int n, int m, int y, int x){
	q.push(make_pair(y, x));
	visited[y][x]=1;
	while(!q.empty()){
		pair<int, int> next = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int ny=next.first+dir[i][0];
			int nx=next.second+dir[i][1];
			if(ny<n&&ny>=0&&nx<m&&nx>=0){
				if(map[ny][nx]&&!visited[ny][nx]){
					q.push(make_pair(ny, nx));
					visited[ny][nx]=1;
				}
			}
		}
	}
}

int main(void){
	int tc;
	scanf("%d", &tc);
	for(int i=0;i<tc ;i++){
		int m, n, k;
		scanf("%d %d %d", &m, &n, &k);
		memset(map, 0, sizeof(map));
		memset(visited,0, sizeof(visited));
		for(int j=0; j<k; j++){
			int y, x;
			scanf("%d %d", &x, &y);
			map[y][x]=1;
		}
		int ans=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(!visited[i][j]&&map[i][j]) {
					bfs(n, m, i, j);
					ans+=1;
				}
			}
		}
		printf("%d\n", ans);
	}
}
