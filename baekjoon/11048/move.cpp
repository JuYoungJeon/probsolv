#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>

using namespace std;
//down, right, dignoal
int dir[3][2]={{1, 0}, {0, 1}, {1, 1}};

queue<pair<int, int> > target;
int map[1001][1001];
int cache[1001][1001];
int visited[1001][1001];

void bfs(int n, int m){
	pair<int, int> curr = make_pair(1, 1);
	target.push(curr);
	while(!target.empty()){
		curr=target.front();
		target.pop();

		cache[curr.first][curr.second]=max(cache[curr.first-1][curr.second], cache[curr.first][curr.second-1]);
		cache[curr.first][curr.second]=max(cache[curr.first][curr.second],cache[curr.first-1][curr.second-1]);
		cache[curr.first][curr.second]+=map[curr.first][curr.second];
		for(int i=0; i<3; i++){
			if(curr.first+dir[i][0]<=0 || curr.first+dir[i][0]>n || curr.second+dir[i][1]<=0 || curr.second+dir[i][1]>m)
				continue;
			if( !visited[curr.first+dir[i][0]][curr.second+dir[i][1]]){
				target.push(make_pair(curr.first+dir[i][0], curr.second+dir[i][1]));
				visited[curr.first+dir[i][0]][curr.second+dir[i][1]]=1;
			}
		}
	}
}

int main(void){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> map[i][j];
		}
	}
	bfs(n, m);
	cout << cache[n][m];
}

//MEMO: MEMORY -> check if duplicate coordinate is pushed into the queue
