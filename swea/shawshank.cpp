#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define pii pair<int, int>
int shape[7][4][2]={{{-1,0},{1,0},{0,-1},{0,1}},{{1,0},{-1,0}},{{0,-1},{0,1}},{{-1,0},{0,1}},{{1,0},{0,1}},{{1,0},{0,-1}},{{-1,0},{0,-1}}};

int main(void){
	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++){
		int N, M, R, C, L;
		cin >> N>>M>>R>>C>>L;
		int map[50][50];
		int check[50][50];
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		for(int i=0;i<N; i++){
			for(int j=0; j<M; j++){
				cin >> map[i][j];
			}
		}
		queue<pii> q;
		q.push({R, C});
		int cnt=1;
		check[R][C]=1;
		while(!q.empty()){
			pii cur = q.front();
			q.pop();
			int sidx=map[cur.first][cur.second]-1;
			int ndir;
			if(sidx==0) ndir=4;
			else ndir=2;
			for(int i=0;i<ndir; i++){
				int ny=cur.first+shape[sidx][i][0];
				int nx=cur.second+shape[sidx][i][1];
				if(ny<0||nx<0||ny>=N||nx>=M) continue;
				if(map[ny][nx]==0) continue;
				if(check[cur.first][cur.second]==L) continue;
				if(check[ny][nx]) continue;
				bool headed=false;
				int d=map[ny][nx]-1;
				int nd=d==0?4:2;
				for(int j=0; j<nd; j++){
					if(ny+shape[d][j][0]==cur.first&&nx+shape[d][j][1]==cur.second) headed=true;
				}
				if(!headed) continue;
				check[ny][nx]=check[cur.first][cur.second]+1;
				cnt+=1;
				q.push({ny,nx});
			}
		}
		cout << cnt <<'\n';
	}
}
