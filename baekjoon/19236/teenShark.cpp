#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
//up -> 45deg left
const int dir[8][2]={{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}}; 
int fishes[16][2];
int map[4][4][2];
int sharkIdx[2];
int ans;

void moveFish(){
	for(int i=0;i<16; i++){
		int y = fishes[i][0];
		int x = fishes[i][1];
		if(y==-1&& x==-1) continue;
		int ny = y+dir[map[y][x][1]][0];
		int nx = x+dir[map[y][x][1]][1];

		int turnIdx=1;
		while(turnIdx<8 && (ny<0||nx<0||ny>=4||nx>=4||map[ny][nx][0]==1000)){
			map[y][x][1]=(map[y][x][1]+1)%8;
			ny = y+dir[map[y][x][1]][0];
			nx = x+dir[map[y][x][1]][1];
			turnIdx+=1;
		}
		if(turnIdx==8) continue;

		if(map[ny][nx][0]>=-1) {
			if(map[ny][nx][0]>-1){
				fishes[map[ny][nx][0]][0]= y;
				fishes[map[ny][nx][0]][1]= x;
			}
			fishes[map[y][x][0]][0]= ny;
			fishes[map[y][x][0]][1]= nx;
			swap(map[ny][nx][0], map[y][x][0]);
			swap(map[ny][nx][1], map[y][x][1]);
		}
	}
}
int getMaxFishNum(int sy, int sx){
	int tmap[4][4][2];
	int tfishes[16][2];
	int ret =0;
	moveFish();
	for(int i=0;i<4; i++){
		for(int j=0;j<4; j++){
			tmap[i][j][0]=map[i][j][0];
			tmap[i][j][1]=map[i][j][1];
		}
	}

	for(int i=0;i<16; i++){
		tfishes[i][0]=fishes[i][0];
		tfishes[i][1]=fishes[i][1];
	}
	int nsy = sy+dir[map[sy][sx][1]][0];
	int nsx = sx+dir[map[sy][sx][1]][1];

	while(!(nsy<0||nsx<0||nsy>=4||nsx>=4)){
		if(map[nsy][nsx][0]!=-1) {
			int fishIdx=map[nsy][nsx][0];
			fishes[fishIdx][0]=-1;
			fishes[fishIdx][1]=-1;
			map[sy][sx][0]=-1;
			map[nsy][nsx][0]=1000;
			ret=max(ret, getMaxFishNum(nsy, nsx)+fishIdx+1);
			for(int i=0;i<4; i++){
				for(int j=0;j<4; j++){
					map[i][j][0]=tmap[i][j][0];
					map[i][j][1]=tmap[i][j][1];
				}
			}
			for(int i=0;i<16; i++){
				fishes[i][0]=tfishes[i][0];
				fishes[i][1]=tfishes[i][1];
			}
		}
		nsy = nsy+dir[map[sy][sx][1]][0];
		nsx = nsx+dir[map[sy][sx][1]][1];
	}
	return ret;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=0;i<4; i++){
		for(int j=0;j<4; j++){
			cin >> map[i][j][0] >> map[i][j][1];
			map[i][j][0]-=1;
			map[i][j][1]-=1;
			fishes[map[i][j][0]][0]=i;
			fishes[map[i][j][0]][1]=j;
		}
	}
	//shark at 0, 0; shark idx ==1000
	int ans = map[0][0][0]+1;
	fishes[ans-1][0]=-1, fishes[ans-1][1]=-1;
	map[0][0][0]=1000;
	cout << ans+getMaxFishNum(0, 0);
}
