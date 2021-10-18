#include<iostream>
#include<cstring>
#include<vector>
#include<tuple>
using namespace std;
#define tiiii tuple<int, int, int, int>
#define pii pair<int, int>
#define ST 1000

typedef struct atom{
	int y, x, d, e;
}atom;

int dir[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int map[4002][4002];
atom atoms[1000];


int main(void){
	int TC;
	cin >> TC;
	for(int test_case=1; test_case<=TC; test_case++){
		memset(map, 0, sizeof(map));
		int N;
		cin >> N;
		for(int i=0;i<N; i++){
			int x, y, d, k;
			cin >> x >> y >> d >> k;
			atoms[i]={(ST-y)*2, (ST+x)*2, d, k};
			map[(ST-y)*2][(ST+x)*2]+=1;
		}
		int ans=0;
		while(1){
			int cnt=0;
			for(int i=0;i<N; i++){
				int cy = atoms[i].y;
				int cx = atoms[i].x;
				int d = atoms[i].d;
				if(cy==-1&&cx==-1) continue;
				int ny = cy+dir[d][0];
				int nx = cx+dir[d][1];
				if(ny<0||nx<0||ny>4000||nx>4000){
					atoms[i].y=-1;
					atoms[i].x=-1;
                    map[cy][cx]-=1;
					continue;
				}
				int td=atoms[map[ny][nx]].d;
				map[ny][nx]+=1;
				map[cy][cx]-=1;
				atoms[i].y=ny;
				atoms[i].x=nx;
				cnt+=1;
			}
			if(cnt<=1) break;
			vector<pii> loc;
			for(int i=0;i<N; i++){
				int cy = atoms[i].y;
				int cx = atoms[i].x;
				if(cy==-1&& cx==-1) continue;
				if(map[cy][cx]<=1) continue;
				else  loc.push_back({cy,cx});
				ans+=atoms[i].e;
				atoms[i].y=-1; atoms[i].x=-1;
			}
			for(auto& l: loc){
				if(map[l.first][l.second]) 
					map[l.first][l.second]=0;
			}
		}
		cout <<'#'<<test_case<<' '<< ans<<'\n';
	}

}
