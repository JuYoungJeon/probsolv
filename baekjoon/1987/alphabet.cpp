#include<cstdio>
#include<algorithm>
using namespace std;
int alph[26];
char board[20][20];
int dir[4][2]={{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int ans=0;

int dfs(int r, int c, int x, int y){
	int ans =0;
	for(int i=0; i<4; i++){
		int dx=x+dir[i][0];
		int dy=y+dir[i][1];
		if(dx<0 || dx>=c || dy<0||dy>=r) continue;
		if (alph[board[dy][dx]-'A']) continue;
		alph[board[dy][dx]-'A']=1;
		ans=max(ans, dfs(r, c, dx, dy)+1);
		alph[board[dy][dx]-'A']=0;
	}
	return ans ;
}

int main(void){
	int r, c;
	scanf("%d %d", &r, &c);
	getchar();
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			scanf("%c", &board[i][j]);
		}
		getchar();
	}
	alph[board[0][0]-'A']=1; 
	ans=dfs(r, c, 0, 0)+1;
	printf("%d", ans);
}
