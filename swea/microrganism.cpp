#include<iostream>
#include<cstring>

using namespace std;

int dir[4][2]={{-1,0},{1,0},{0,-1},{0 ,1}};

struct cell{
	int y, x;
	int num;
	int d;
	bool alive=true;
	int toAdd=0;
	void reset(){y=0; x=0; d=0; num=0; toAdd=0; alive=true;}
};

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;
	for(int test_case=0; test_case<T; test_case++){
		int N, M, K;
		cin >> N >> M >> K;
		cell micro[1001];
		int map[101][101];
		memset(map, 0, sizeof(map));
		for(int i=1;i<=K; i++){
			micro[i].reset();
			int y, x, nu, d;
			cin >> y >> x>>nu>>d;
			micro[i].y=y; micro[i].x=x;
			micro[i].num=nu; micro[i].d=d;
			map[y][x]=i;
		}
		for(int t=0;t<M; t++){
			for(int c=1; c<=K; c++){
				if(!micro[c].alive)continue;
				int ny = micro[c].y+dir[micro[c].d-1][0];
				int nx = micro[c].x+dir[micro[c].d-1][1];
				if(ny==0||nx==0||ny==N-1||nx==N-1){
					if(micro[c].d==1||micro[c].d==3) micro[c].d+=1;
					else micro[c].d-=1;
					micro[c].num/=2;
					if(!micro[c].num) micro[c].alive=false;
				}
				if(map[micro[c].y][micro[c].x]== c) map[micro[c].y][micro[c].x]=0;
				if(map[ny][nx]!=0&&map[ny][nx]<c){
					if(micro[map[ny][nx]].num<=micro[c].num){
						micro[map[ny][nx]].alive=false;
						micro[c].toAdd+=(micro[map[ny][nx]].num+micro[map[ny][nx]].toAdd);
						micro[c].y=ny; micro[c].x=nx;
						map[ny][nx]=c;
					}else{
						micro[c].alive=false;
						micro[map[ny][nx]].toAdd+=(micro[c].num+micro[c].toAdd);
					}
				}else {
					map[ny][nx]=c;
					micro[c].y=ny; micro[c].x=nx;
				}
			}
			for(int c=1; c<=K; c++){
				micro[c].num+=micro[c].toAdd;
				micro[c].toAdd=0;
			}
		}
		int ans=0;
		for(int c=1; c<=K; c++){
			if(micro[c].alive) ans+=micro[c].num;
		}
		cout <<'#'<<test_case+1<<' '<< ans<<'\n';
	}
}
