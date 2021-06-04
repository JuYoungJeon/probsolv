#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
//up,right, down, left
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int map[8][8];
int rotateDir[5]={4,2,4,4,1};
vector<int> cctv[5];
vector<pair<int, int> > cctvloc;
void printMap(int n, int m){
	for(int i=0;i <n; i++){
		for(int j=0; j<m; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int dfs(int n, int m, int idx){
	if(idx==cctvloc.size()) return 0;
	int maxWatched=0;
	pair<int, int> ncctv=cctvloc[idx];
	int prevMap[8][8];
	copy(&map[0][0], &map[0][0]+8*8, &prevMap[0][0]);
	for(int i=0; i<rotateDir[map[ncctv.first][ncctv.second]-1]; i++){
		int watched=0;
		for(auto &j : cctv[map[ncctv.first][ncctv.second]-1]){
			int ny=ncctv.first+dir[(j+i)%4][0]; 
			int nx=ncctv.second+dir[(j+i)%4][1];
			while(ny>=0&&nx>=0&&ny<n&&nx<m){
				if(map[ny][nx]==6) break;
				if(map[ny][nx]==0) {
					map[ny][nx]=map[ncctv.first][ncctv.second];
					watched+=1;
				}
				ny += dir[(j+i)%4][0];
				nx += dir[(j+i)%4][1];
			}
		}
		watched+=dfs(n, m, idx+1);
		copy(&prevMap[0][0], &prevMap[0][0]+8*8, &map[0][0]);
		maxWatched=max(watched, maxWatched);
	}
	return maxWatched;

}
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	int unwatched=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j]>0&&map[i][j]<6) cctvloc.push_back(make_pair(i, j));
			if(map[i][j]==0) unwatched+=1;
		}
	}
	cctv[0].push_back(1);
	cctv[1].push_back(1); cctv[1].push_back(3);
	cctv[2].push_back(0); cctv[2].push_back(1);
	cctv[3].push_back(3); cctv[3].push_back(0); cctv[3].push_back(1);
	for(int i=0; i<4; i++) cctv[4].push_back(i);
	printf("%d", unwatched-dfs(n,m,0));
}
