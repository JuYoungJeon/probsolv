#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M;
vector<pair<int, int>> lights[101][101];
int visited[101][101][2];
int dir[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool canVisit(pair<int, int> c){
	if(c.first==1&&c.second==1) return true;
	for(int i=0;i<4; i++){
		int ny=c.first+dir[i][0];
		int nx=c.second+dir[i][1];
		if(ny<=0||ny>N||nx<=0||ny>N) continue;
		if(visited[ny][nx][1]==1) return true;
	}
	return false;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	for(int i=0;i<M; i++){
		int x, y, a, b;
		cin>>x>>y>>a>>b;
		lights[x][y].push_back({a, b});
	}
	queue<pair<int, int>> q;
	int cnt=1;
	visited[1][1][0]=1;
	q.push({1, 1});
	while(!q.empty()){
		pair<int, int> c=q.front();
		q.pop();
		if(!canVisit(c)) continue;
		if(visited[c.first][c.second][1]==1) continue;
		visited[c.first][c.second][1]=1;
		for(auto n:lights[c.first][c.second]){
			if(visited[n.first][n.second][0]==1) continue;
			visited[n.first][n.second][0]=1;
			cnt+=1;
			q.push(n);
		}
		for(int i=0;i<4; i++){
			int ny=c.first+dir[i][0];
			int nx=c.second+dir[i][1];
			if(ny<=0||ny>N|| nx<=0||ny>N) continue;
			if(visited[ny][nx][0]==1&&visited[ny][nx][1]==0) {
				q.push({ny, nx});
			}
		}
	}
	cout << cnt;
}
