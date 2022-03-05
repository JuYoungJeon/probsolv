#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int dir[4][2]={{1,0}, {-1, 0}, {0, 1}, {0, -1}};
int N;
char map[100][100];
int visitedA[100][100];
int visitedB[100][100];

bool colorBlindCheck(int c1, int c2){
	return (c1=='R'||c1=='G')&&(c2=='R'||c2=='G');
}

void bfs(int y, int x, int idx, bool colorBlind){
	queue<pair<int, int>> q;
	q.push({y, x});
	if(!colorBlind)visitedA[y][x]=idx;
	if(colorBlind)visitedB[y][x]=idx;
	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		for(int i=0;i<4; i++){
			int ny = cur.first+dir[i][0];
			int nx = cur.second+dir[i][1];
			if(ny<0||ny>=N||nx<0||nx>=N) continue;
			if(!colorBlind&&visitedA[ny][nx]) continue;
			if(colorBlind&&visitedB[ny][nx]) continue;
			if(map[cur.first][cur.second]==map[ny][nx]){
				if(!colorBlind)	visitedA[ny][nx]=visitedA[cur.first][cur.second];
				if(colorBlind) visitedB[ny][nx]=visitedB[cur.first][cur.second];
				q.push({ny, nx});
			}else if(colorBlind&&colorBlindCheck(map[ny][nx], map[y][x])){
				visitedB[ny][nx]=visitedB[cur.first][cur.second];
				q.push({ny, nx});
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(visitedA, 0, sizeof(visitedA));
	memset(visitedB, 0, sizeof(visitedB));
	cin >> N;

	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			cin >> map[i][j];
		}
	}
	int ansA=0;
	int ansB=0;
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			if(!visitedA[i][j]) bfs(i, j, ++ansA, false);
			if(!visitedB[i][j]) bfs(i, j, ++ansB, true);
		}
	}
	cout << ansA<<' '<< ansB;

}
