#include<cstdio>
#include<queue>
using namespace std;
int map[1000][1000];
int r, c;
queue<pair<int, int> > fire;
queue<pair<int, int> > q;
int dir[4][2]={{1,0}, {-1,0}, {0, -1}, {0, 1}};

void bfs(){
	while(!fire.empty()){
		pair<int, int> f= fire.front();
		fire.pop();
		for(int i=0; i<4; i++){
			int dy = f.first+dir[i][0];
			int dx = f.second+dir[i][1];
			if(map[dy][dx]==2000) continue;
			if(dy<0||dx<0||dy>=r||dx>=c) {
				continue;
			}
			if(map[dy][dx]!=0) continue;
			map[dy][dx]=map[f.first][f.second]-1;
			fire.push(make_pair(dy, dx));
		}
	}
	int t=1001;
	while(!q.empty()){
		pair<int, int> j = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int dy = j.first+dir[i][0];
			int dx = j.second+dir[i][1];
			if(map[dy][dx]<0&&map[dy][dx]*-1<=map[j.first][j.second]+1) continue;
			if(map[dy][dx]>0) continue;
			if(dy<0||dx<0||dy>=r||dx>=c) {
				continue;
			}
			map[dy][dx]=map[j.first][j.second]+1;
			q.push(make_pair(dy, dx));
		}
	}
}

int main(void){
	scanf("%d %d", &r, &c);
	getchar();
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			char c;
			scanf("%c", &c);
			if(c=='J'){
				map[i][j]=1;
				q.push(make_pair(i, j));
			}else if(c=='F'){
				map[i][j]=-1;
				fire.push(make_pair(i, j));
			}else if(c=='#'){
				map[i][j]=2000;
			}else map[i][j]=0;
		}
		getchar();
	}

	bfs();
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	int time=1001;
	for(int i=0; i<r; i++) {
		if(map[i][0]>0) time=min(time, map[i][0]);
		if(map[i][c-1]>0) time=min(time, map[i][c-1]);
	}
	for(int i=0; i<c; i++){
		if(map[0][i]>0) time=min(time, map[0][i]);
		if(map[r-1][i]>0)time=min(time, map[r-1][i]);
	}
	if(time==1001) printf("IMPOSSIBLE");
	else printf("%d", time);
}
