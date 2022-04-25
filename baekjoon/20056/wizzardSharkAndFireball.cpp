#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

struct fireball{
	int y, x;
	int m, s, d;
};

const int dir[8][2]={{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
vector<int> map[51][51];
vector<fireball> fs;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, K;
	cin >> N >> M >> K;

	for(int i=0;i<M; i++){
		fireball f;
		cin >> f.y >> f.x>> f.m >> f.s>>f.d;
		fs.push_back(f);
		map[f.y][f.x].push_back(i);
	}

	for(int i=0;i<K; i++){
		//move fireballs
		for(int y=1;y <= N; y++){
			for(int x=1;x<=N; x++){
				map[y][x].clear();
			}
		}
		for(int fi=0; fi<fs.size(); fi++){
			if(fs[fi].y==-1&&fs[fi].x==-1) continue;
			int ny = (fs[fi].y+dir[fs[fi].d][0]*fs[fi].s);
			int nx = (fs[fi].x+dir[fs[fi].d][1]*fs[fi].s);
			if(ny<1) while(ny<1) ny += N;
			else if (ny>N) while(ny>N)ny-=N;
			if(nx<1) while(nx<1) nx += N;
			else if(nx>N) while(nx>N) nx-=N;
			map[ny][nx].push_back(fi);
			fs[fi].y = ny;
			fs[fi].x = nx;
		}
		//combine
		for(int y=1; y<=N; y++){
			for(int x=1;x<=N; x++){
				if(map[y][x].size()>1){
					int nm=0, ns=0;
					int checkdir=fs[map[y][x][0]].d%2;
					bool evenDir=true;;
					for(auto f: map[y][x]){
						nm+=fs[f].m;
						ns+=fs[f].s;
						if(fs[f].d%2!=checkdir) evenDir=false;
						fs[f].y=-1;
						fs[f].x=-1;
					}
					if(nm/5==0){
						map[y][x].clear();
						continue;
					}
					int startIdx;
					for(int i=0;i<4; i++){
						if(i==0) startIdx=fs.size();
						fireball f={y, x, nm/5, ns/((int)map[y][x].size()), i*2+(!evenDir)};
						fs.push_back(f);
					}
					map[y][x].clear();
					for(int i=0;i<4; i++){
						map[y][x].push_back(startIdx+i);
					}
				}
			}
		}
	}
	int ans =0;
	for(auto f: fs){
		if(f.x!=-1&& f.y!=-1) ans+=f.m;
	}
	cout << ans;
}
