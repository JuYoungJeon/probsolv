#include<cstdio>
#include<string>
using namespace std;
int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int n, m;
char map[50][50];
int visited[50][50];
bool dfs(int y, int x, int py, int px, char c){
	if(visited[y][x]) return true;
	visited[y][x]=1;
	bool ret =false;
	for(int i=0; i<4; i++){
		int dy=y+dir[i][0];
		int dx=x+dir[i][1];
		if(dy<0||dy>=n||dx<0||dx>=m) continue;
		if(dy==py&&dx==px) continue;
		if(map[dy][dx]!=c) continue;
		ret += dfs(dy, dx, y, x, c);
	}
	return ret;
}

int main(void){
	scanf("%d %d", &n, &m);
	getchar();
	for(int i=0; i<n; i++){
		for(int j=0;j<m; j++){
			scanf("%c", &map[i][j]);
		}
		getchar();
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(visited[i][j]) continue;
			if(dfs(i, j, -1, -1, map[i][j])){
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
}
//ret을 설정할때 ret=dfs()하게 되면 이전에 사이클이 발견되도 overwrite될수도있어 +=사용
