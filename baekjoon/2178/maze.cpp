#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;
int visited[101][101]={0};
int map[101][101]={0};
int shortest[101][101]={0};
//down, right, up, left
int dir[4][2] = {{1,0},{0,1}, {-1, 0}, {0, -1}};
queue<pair<int, int> > q;

void printMap(int n, int m){
	for (int i=0; i< n; i++){
		for(int j=0; j<m; j++){
			cout << shortest[i][j]<<' ';
		}
		cout << '\n';
	}
}

int solution(int n, int m){
	int x=0, y=0;
	int pathNum=1;
	visited[y][x]=1;
	q.push(make_pair(y, x));
	shortest[y][x]=pathNum;
	while(!q.empty()){
		pair<int, int> next = q.front();
		q.pop();
		pathNum= shortest[next.first][next.second]+1;
		for(int i=0; i<4; i++){
			int next_y = next.first+dir[i][0];
			int next_x = next.second+dir[i][1];
			if (next_y>=0 &&next_y<n && next_x>=0 && next_x < m){
				if(visited[next_y][next_x]==0 && map[next_y][next_x]==1){
					shortest[next_y][next_x]=pathNum;
					visited[next_y][next_x]=1;
					q.push(make_pair(next_y, next_x));
				}
			}
		}
	}
	return shortest[n-1][m-1];
}

int main(void){
	int n, m;
	cin >> n >> m;
	int minimumPath=n*m;
	for (int i=0; i< n; i++){
		for(int j=0; j< m; j++){
			char t;
			cin >> t;
			map[i][j]=t-'0';
			shortest[i][j]=n*m;
		}
	}
	cout << solution(n, m);
}
