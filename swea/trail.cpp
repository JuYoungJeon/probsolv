#include<iostream>

using namespace std;

int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int map[8][8];
int dp[8][8];
int mh;

int fwd(int N, int y, int x){
	int ret =0;
	for(int d=0;d<4; d++){
		int ny = y+dir[d][0];
		int nx = x+dir[d][1];
		if(ny<0||nx<0||ny>=N||nx>=N) continue;
		if(map[y][x]>=map[ny][nx]) continue;
		ret=max(ret, 1+fwd(N, ny, nx));
	}
	if(ret==0&&map[y][x]!=mh) ret=-10000;
	return ret;
}

int bwd(int N, int y, int x){
	int ret =0; 
	for(int d=0;d<4; d++){
		int ny = y+dir[d][0];
		int nx = x+dir[d][1];
		if(ny<0||nx<0||ny>=N||nx>=N) continue;
		if(map[y][x]<=map[ny][nx]) continue;
		ret=max(ret, bwd(N, ny, nx)+1);
	}
	return ret;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++){
		int N, K;
		int ans=0;
		mh=0;
		memset(map, 0, sizeof(map));
		memset(dp, 0, sizeof(dp));
		cin >> N >> K;
		for(int i=0;i<N; i++){
			for(int j=0;j<N; j++){
				cin >> map[i][j];
				mh=max(mh, map[i][j]);
			}
		}
		for(int i=0;i<N; i++){
			for(int j=0;j<N; j++){
				for(int k=0;k<=K; k++){
					map[i][j]-=k;
					ans=max(ans, fwd(N, i, j)+bwd(N, i,j));
					map[i][j]+=k;
				}
			}
		}
		cout << '#'<<test_case<<' '<<ans+1<<'\n';
	}
}
