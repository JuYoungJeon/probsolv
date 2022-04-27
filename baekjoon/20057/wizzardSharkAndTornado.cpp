#include<iostream>
#include<tuple>

using namespace std;

int map[500][500];
const int dir[4][2]={{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
tuple<int,int,double> dust[10]={{-1,0,0.01}, {1, 0, 0.01}, {-1, -1, 0.07}, {1, -1, 0.07}, {-2, -1, 0.02}, {2, -1, 0.02}, {-1, -2, 0.1}, {1, -2, 0.1}, {0, -3, 0.05}, {0, -2, 1}};
int N;
int ans;
void windTo(int y, int x, int ny, int nx, int d){
	int rem = map[ny][nx];
	for(int i=0;i<10; i++){
		int yy, xx;
		switch (d){
			case 0:
				yy = y+get<0>(dust[i]);
				xx = x+get<1>(dust[i]);
				break;
			case 1:
				yy = y-get<1>(dust[i]);
				xx = x+get<0>(dust[i]);
				break;
			case 2:
				yy = y+get<0>(dust[i]);
				xx = x-get<1>(dust[i]);
				break;
			case 3:
				yy = y+get<1>(dust[i]);
				xx = x-get<0>(dust[i]);
				break;
		}
		if(yy<0||xx<0||yy>=N||xx>=N){
			if(i==9) ans += rem;
			else {
				ans+= (int)(map[ny][nx]*get<2>(dust[i]));
				rem-= (int)(map[ny][nx]*get<2>(dust[i]));
			}
			continue;
		}
		if(i==9) map[yy][xx]+= rem;
		else{
			map[yy][xx]+=(int)(map[ny][nx]*get<2>(dust[i]));
			rem -= (int)(map[ny][nx]*get<2>(dust[i]));
		}

	}
	map[ny][nx]=0;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N; 
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			cin >> map[i][j];
		}
	}

	int dirLen=1;
	int numDir=0;
	int y = N/2, x = N/2;
	int dIdx = 0;
	while(y!=0 || x!=0){
		for(int i=0;i<dirLen; i++){
			windTo(y, x, y+dir[dIdx][0], x+dir[dIdx][1], dIdx);
			y+=dir[dIdx][0];
			x+=dir[dIdx][1];
			if(y==0&& x==0) break;
		}
		if(numDir==1) {
			numDir=0;
			dirLen+=1;
		}else numDir+=1;
		dIdx=(dIdx+1)%4;
	}
	cout << ans;
}
