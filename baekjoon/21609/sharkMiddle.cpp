#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int dir[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int map[20][20];
int visited[20][20];
int tmpvis[20][20];
int N, M;

struct block{
	int y, x, n, r;
};
block lar ={-1, -1, 1, 0};

void printMap(){
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			cout << map[i][j]<<' ';
		}cout <<'\n';;
	}
	cout <<'\n';
}

void BFS(int y, int x){
	memset(tmpvis, 0, sizeof(tmpvis));
	queue<pair<int, int>> pq;
	int num = map[y][x];
	visited[y][x]=1;
	tmpvis[y][x]=1;
	pq.push({y, x});
	int nb=1;
	int nr =0;
	while(!pq.empty()){
		pair<int, int> t = pq.front();
		pq.pop();
		for(int d=0;d<4; d++){
			int ny = t.first+dir[d][0];
			int nx = t.second+dir[d][1];
			if(ny<0||nx<0||ny>=N||nx>=N) continue;
			if(map[ny][nx]!=0&&map[ny][nx]!=num) continue;
			if(tmpvis[ny][nx]) continue;
			tmpvis[ny][nx]=1;
			visited[ny][nx]=1;
			nb+=1;
			if(map[ny][nx]==0) nr+=1;
			pq.push({ny, nx});
		}
	}
	if(nb>lar.n) {
		lar.y = y;
		lar.x = x;
		lar.n = nb;
		lar.r = nr;
	}
	if(nb==lar.n&&nr>=lar.r){
		lar.y= y;
		lar.x=x;
		lar.n=nb;
		lar.r=nr;
	}
}

void remove(){
	queue<pair<int, int>> pq;
	memset(tmpvis, 0, sizeof(tmpvis));
	int num=map[lar.y][lar.x];
	pq.push({lar.y, lar.x});
	map[lar.y][lar.x]=M+1;
	tmpvis[lar.y][lar.x]=1;
	while(!pq.empty()){
		pair<int, int> t = pq.front();
		pq.pop();
		for(int d=0;d<4; d++){
			int ny = t.first+dir[d][0];
			int nx = t.second+dir[d][1];
			if(ny<0||nx<0||ny>=N||nx>=N) continue;
			if(map[ny][nx]!=num&&map[ny][nx]!=0) continue;
			if(tmpvis[ny][nx]) continue;
			tmpvis[ny][nx]=1;
			map[ny][nx]=M+1;
			pq.push({ny, nx});
		}
	}
}

void rotate(){
	int tmp[20][20];
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			tmp[i][j]=map[i][j];
		}
	}
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			map[i][j]=tmp[j][N-i-1];
		}
	}
}

void gravity(){
	for(int j=0;j<N; j++){
		for(int i=N-2; i>=0; i--){
			if(map[i][j]==-1) continue;
			if(map[i][j]==M+1) continue;
			int t=i;
			while(t+1<N && map[t+1][j]!=-1 && map[t+1][j]==M+1 ) t++;
			if(map[t][j]!=M+1) continue;
			map[t][j]=map[i][j];
			map[i][j]=M+1;
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			cin >> map[i][j];
		}
	}
	int ans=0;
	while(1){
		memset(visited, 0, sizeof(visited));
		lar = {-1, -1, 1, 0};
		for(int i=0;i<N; i++){
			for(int j=0;j<N;j++){
				if(map[i][j]==-1) continue;
				if(map[i][j]==M+1) continue;
				if(map[i][j]==0) continue;
				if(visited[i][j]) continue;
				BFS(i, j);
			}
		}
		if(lar.n==1) break;
		ans+=(lar.n*lar.n);
		remove();
		gravity();
		rotate();
		gravity();
	}
	cout << ans;
}
