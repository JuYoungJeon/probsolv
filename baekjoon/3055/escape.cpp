#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define pii pair<int, int>

int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
char map[50][50];
queue<pii> w, h;

void printMap(int r, int c){
	for(int i=0;i<r; i++) {
		for(int j=0;j<c; j++){
			cout<<map[i][j]<<' ';
		}cout <<'\n';
	}
}

int bfs(int r, int c){
	int cnt =0;
	while(1){
		//Water movement
		cnt+=1;
		int wsize = w.size();
		for(int i=0;i<wsize; i++){
			pii water = w.front();
			w.pop();
			for(int j=0;j<4; j++){
				int dy = water.first+dir[j][0];
				int dx = water.second+dir[j][1];
				if(dy<0||dy>=r||dx<0||dx>=c) continue;
				if(map[dy][dx]=='*') continue;
				if(map[dy][dx]=='D'||map[dy][dx]=='X') continue;
				map[dy][dx]='*';
				w.push({dy, dx});
			}
		}
		bool hmoved=false;
		int hsize=h.size();
		for(int i=0;i<hsize; i++){
			pii hedge = h.front();
			h.pop();
			for(int j=0;j<4; j++){
				int dy = hedge.first+dir[j][0];
				int dx = hedge.second+dir[j][1];
				if(dy<0||dy>=r||dx<0||dx>=c) continue;
				if(map[dy][dx]=='D') {return cnt;}
				if(map[dy][dx]!='.') continue;
				hmoved=true;
				map[dy][dx]='S';
				h.push({dy, dx});
			}
		}
		if(!hmoved) return -1;
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int r, c;
	cin >> r>> c;
	for(int i=0;i<r; i++){
		for(int j=0;j<c; j++){
			cin >> map[i][j];
			if(map[i][j]=='S'){ h.push({i, j}); }
			if(map[i][j]=='*'){ w.push({i, j}); }
		}
	}
	int ans = bfs(r, c);
	if(ans==-1) cout << "KAKTUS";
	else cout << ans;
}
