#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int map[50][50];
int t[50][50];
int dir[4][2]={{1, 0}, {-1,0},{0,-1},{0,1}};

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	cin >> N>> M;
	vector<pair<int, int>> virus; 
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			cin >> map[i][j];
			if(map[i][j]==2) virus.push_back({i, j});
		}
	}
	vector<int> comb;
	for(int i=0;i<virus.size()-M; i++) comb.push_back(0);
	for(int i=0;i<M; i++) comb.push_back(1);
	int answer=N*N+1;
	do{
		queue<pair<int, int>> q;
		for(int i=0;i<N; i++){
			for(int j=0;j<N; j++){
				if(map[i][j]==1) t[i][j]=-1;
				else if(map[i][j]==0) t[i][j]=N*N+1;
				else t[i][j]=-2;
			}
		}
		for(int i=0;i<comb.size(); i++){
			if(comb[i]==1){
				q.push(virus[i]);
				t[virus[i].first][virus[i].second]=0;
			}
		}

		while(!q.empty()){
			pair<int, int> curr = q.front();
			q.pop();
			for(int i=0;i<4; i++){
				int ny = curr.first+dir[i][0];
				int nx = curr.second+dir[i][1];
				if(ny<0||nx<0||ny>=N||nx>=N) continue;
				if(t[ny][nx]==-1)continue;
				if(t[ny][nx]!=-2&&t[ny][nx]<=t[curr.first][curr.second]+1) continue;
				t[ny][nx]=t[curr.first][curr.second]+1;
				q.push({ny, nx});
			}
		}
		int cost= 0;
		for(int i=0;i<N; i++){
			for(int j=0;j<N; j++){
				if(map[i][j]==2) continue;
				else cost=max(cost, t[i][j]);
			}
		}
		answer=min(answer, cost);
	}while(next_permutation(comb.begin(), comb.end()));
	if(answer==N*N+1) cout << "-1";
	else cout << answer;
}
