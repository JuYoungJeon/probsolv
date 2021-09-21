#include<iostream>
#include<cstring>

using namespace std;

#define pii pair<int, int>

int dir[4][2]={{1,-1},{1,1},{-1,1},{-1,-1}};
int map[20][20];
int visited[20][20];
int check[101];
int dfs(int y, int x, int N, int d){
	int ret =-1;
	for(int i=0; i<2; i++){
		if(d+i>3) continue;
		int ny = y+dir[d+i][0];
		int nx = x+dir[d+i][1];
		if(ny<0||nx<0||ny>=N||nx>=N) continue;
		if(visited[ny][nx]==1&&visited[y][x]>3)ret=max(ret, visited[y][x]);
		if(visited[ny][nx]) continue;
		if(check[map[ny][nx]]) continue;
		check[map[ny][nx]]=1;
		visited[ny][nx]=visited[y][x]+1;
		ret=max(ret, dfs(ny, nx, N, d+i));
		visited[ny][nx]=0;
		check[map[ny][nx]]=0;
	}
	return ret;
}
int main(void){
	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++){
		int N; 
		cin>> N;
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		memset(visited, 0, sizeof(visited));
		for(int i=0;i<N; i++){
			for(int j=0;j<N; j++){
				cin >> map[i][j];
			}
		}
		int ans=-1;
		for(int i=0; i<N-2; i++){
			for(int j=1; j<N-1; j++){
				check[map[i][j]]=1;
				visited[i][j]=1;
				ans= max(ans, dfs(i, j, N, 0));
				check[map[i][j]]=0;
				visited[i][j]=0;
			}
		}
		cout << '#'<<test_case<<' '<<ans<<'\n';
	}
}
