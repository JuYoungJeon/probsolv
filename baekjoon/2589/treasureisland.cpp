#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int map[51][51];
int visited[51][51];
int dir[4][2]={{1,0},{-1,0},{0,1},{0, -1}};
queue<pair<int, int> > q;
void printMap(int y, int x){
	for(int i=1; i<=y; i++){
		for(int j=1; j<=x; j++)	cout << map[i][j]<<' ';
		cout <<'\n';
	}
	cout <<'\n';
}
int bfs(int y, int x, pair<int, int> s){
	int maxDist=0;
	q.push(s);
	visited[s.first][s.second]=1;
	while(!q.empty()){
		pair<int, int> n = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int ny = n.first+dir[i][0];
			int nx = n.second+dir[i][1];
			if(ny>y||ny<1||nx>x||nx<1) continue;
			if(map[ny][nx]==0) continue;
			if(visited[ny][nx]==0|| visited[ny][nx]>visited[n.first][n.second]+1) {
				visited[ny][nx]=visited[n.first][n.second]+1;
				q.push(make_pair(ny, nx));
				maxDist=max(maxDist, visited[ny][nx]);
			}
		}
	}
	return maxDist-1;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int y, x;
	cin >> y >> x;
	vector<pair<int, int> > land;
	memset(visited, 0, sizeof(visited));
	memset(map, 0, sizeof(map));
	for(int i=1; i<=y; i++){
		for(int j=1; j<=x; j++){
			char ch;
			cin >> ch;
			if(ch=='L') {map[i][j]=1; land.push_back(make_pair(i, j));}
		}
		cin.ignore();
	}
	int maxLen=0;
	for(auto &l : land){
		maxLen=max(maxLen, bfs(y, x, l));
		memset(visited, 0, sizeof(visited));
	}
	cout << maxLen;
}
