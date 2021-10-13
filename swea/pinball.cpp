#include<iostream>
#include<vector>

using namespace std;

int map[100][100];
vector<pair<int, int>> wormhole[5];
int blockDir[4][2][2]={{{-1,0},{0,1}},{{0,1},{1,0}},{{1,0},{0,-1}},{{0,-1},{-1,0}}};
int dir[4][2]={{1,0},{0,-1}, {-1, 0}, {0,1}};

int dfs(int N, int sy, int sx, int cy, int cx, int dy, int dx){
	int ret =0;
	int ny, nx;
	while(true){
		ny=cy+dy;
		nx=cx+dx;
		if(ny>=N||nx>=N||ny<0||nx<0||(map[ny][nx]==5)){
			ret+=1;
			dy=dy*-1;
			dx=dx*-1;
		}else if(map[ny][nx]==-1||(ny==sy&&nx==sx)) break;
		else if(map[ny][nx]>=1&&map[ny][nx]<5){
			ret+=1;
			if(blockDir[map[ny][nx]-1][0][0]+ny==cy&&blockDir[map[ny][nx]-1][0][1]+nx==cx){
				dy=blockDir[map[ny][nx]-1][1][0];
				dx=blockDir[map[ny][nx]-1][1][1];
			}else if(blockDir[map[ny][nx]-1][1][0]+ny==cy&&blockDir[map[ny][nx]-1][1][1]+nx==cx){
				dy=blockDir[map[ny][nx]-1][0][0];
				dx=blockDir[map[ny][nx]-1][0][1];
			}else{
				dy=dy*-1;
				dx=dx*-1;
			}
		}else if(map[ny][nx]>5){
			pair<int, int> f = wormhole[map[ny][nx]-6][0];
			pair<int, int> s = wormhole[map[ny][nx]-6][1];
			if(f.first==ny&&f.second==nx){
				ny=s.first;
				nx=s.second;
			}else{
				ny=f.first;
				nx=f.second;
			}
		}
		cy=ny; cx=nx;
	}
	return ret;

}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++){
		int N;
		cin >> N;
		for(int i=0;i<5; i++) wormhole[i].clear();
		for(int i=0;i<N; i++){
			for(int j=0;j<N; j++){
				cin >> map[i][j];
				if(map[i][j]>5&&map[i][j]<11) wormhole[map[i][j]-6].push_back({i, j});
			}
		}
		int ans=0;
		for(int i=0;i<N; i++){
			for(int j=0;j<N; j++){
				if(map[i][j]) continue;
				for(int d=0;d<4; d++){
					ans=max(ans, dfs(N, i, j, i, j, dir[d][0], dir[d][1]));
				}
			}
		}
		cout << '#'<< test_case<<' '<<ans<<'\n';
	}
}
//NOTE: Recursive로 구현할 경우 Stack 이 너무 커져서 runtime error 남 -> 반복문으로 구현
