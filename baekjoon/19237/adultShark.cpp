#include<iostream>
#include<vector>

using namespace std;
//up, down, left, right
const int dir[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int map[20][20];
int smell[20][20][2];
int sdir[400];
int spri[400][4][4];
pair<int, int> sharks[400];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, k;
	cin >> N >> M >> k;
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			cin >> map[i][j];
			if(map[i][j]>0){
				sharks[map[i][j]-1]={i, j};
				smell[i][j][0]=map[i][j];
				smell[i][j][1]=k;
			}
		}
	}
	for(int i=0;i<M; i++){
		cin >> sdir[i];
		sdir[i]-=1;
	}
	for(int i=0;i<M; i++){
		for(int j=0;j<4; j++){
			for(int k=0;k<4; k++){
				cin >> spri[i][j][k];
				spri[i][j][k]-=1;
			}
		}
	}
	int nshark=M;
	int time =0;
	while(nshark>1&&time <1001){
		//move to block with no smell / smell of itself
		for(int sidx=0;sidx<M; sidx++){
			if(sharks[sidx].first==-1&& sharks[sidx].second==-1) continue;
			int ndir=-1;
			for(int d=0; d<4; d++){
				int ny = sharks[sidx].first+dir[spri[sidx][sdir[sidx]][d]][0];
				int nx = sharks[sidx].second+dir[spri[sidx][sdir[sidx]][d]][1];
				if(ny<0||nx<0||ny>=N||nx>=N) continue;
				if(smell[ny][nx][0]==0) {
					ndir=spri[sidx][sdir[sidx]][d];
					break;
				}
				if(ndir==-1&&smell[ny][nx][0]==sidx+1) ndir=spri[sidx][sdir[sidx]][d];
			}
			sdir[sidx]=ndir;
			int ny = sharks[sidx].first+dir[ndir][0];
			int nx = sharks[sidx].second+dir[ndir][1];
			map[sharks[sidx].first][sharks[sidx].second]=0;
			if(map[ny][nx]!=0) {
				nshark-=1;
				sharks[sidx]={-1, -1};
				continue;
			}
			map[ny][nx]=sidx+1;
			sharks[sidx]={sharks[sidx].first+dir[ndir][0], sharks[sidx].second+dir[ndir][1]};
		}
		//remove trace
		for(int i=0;i<N; i++){
			for(int j=0;j<N; j++){
				if(smell[i][j][0]!=0){
					smell[i][j][1]-=1;
					if(smell[i][j][1]==0) smell[i][j][0]=0;
				}
			}
		}
		for(int i=0; i<M; i++){
			smell[sharks[i].first][sharks[i].second][0]=i+1;
			smell[sharks[i].first][sharks[i].second][1]=k;
		}
		time++;
	}
	if(time==1001) cout << -1;
	else cout << time;
}
