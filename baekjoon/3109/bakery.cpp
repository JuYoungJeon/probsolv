#include<cstdio>
using namespace std;
int dir[3][2]={{-1,1},{0,1},{1,1}};
int map[10000][500];
int r, c;
int dfs(int y, int x){
	if(x==c) return 1;
	if(y>=r||y<0) return 0;
	if(map[y][x]==1) return 0;
	map[y][x]=1;
	for(int i=0;i<3; i++){
		int dy = y + dir[i][0];
		int dx = x + dir[i][1];
		if(dfs(dy, dx)) return 1;
	}
	return 0;
}
int main(void){
	scanf("%d %d", &r, &c);
	getchar();
	for(int i=0; i<r; i++){
		for(int j=0;j<c; j++){
			char c;
			scanf("%c", &c);
			if(c=='x') map[i][j]=1;
		}
		getchar();
	}
	int ans=0;
	for(int i=0; i<r; i++){
		ans+=dfs(i, 0);
	}
	printf("%d", ans);
}
//NOTE: 최적의 방법 구하는 것이 아니기에 방문한노드를 지울 필요 없음
