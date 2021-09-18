#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define pii pair<int, int>
pii map[700][700];

struct cmp{
	bool operator()(pii a, pii b){
		pii ma=map[a.first][a.second];
		pii mb=map[b.first][b.second];
		if(ma.first+ma.second/2==mb.first+mb.second/2) return ma.second<mb.second;
		else return ma.first+ma.second/2>mb.first+mb.second/2;
	}
};

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int tc;
	cin >> tc;
	int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	for(int t=1;t<=tc; t++){
		for(int i=0;i<700; i++) {
			for(int j=0; j<700; j++){
				map[i][j]={0,0};
			}
		}
		int N, M, K;
		cin >> N >> M >> K;
		priority_queue<pii, vector<pii>, cmp> pq;
		for(int i=0;i<N; i++){
			for(int j=0;j<M; j++){
				int tmp;
				cin >> tmp;
				if(tmp!=0) {map[i+K+1][j+K+1]={0, tmp*2};pq.push({i+K+1, j+K+1});}
			}
		}
		int cnt =0;
		while(!pq.empty()){
			pii curIdx=pq.top();
			pii cur = map[pq.top().first][pq.top().second];
			if(cur.first<=K &&cur.first+cur.second>K) cnt+=1;
			pq.pop();
			if(cur.first+cur.second/2+1>K)continue;
			for(int i=0;i<4; i++){
				int ny =curIdx.first+dir[i][0];
				int nx = curIdx.second+dir[i][1];
				pii next = map[ny][nx];
				if(next.second!=0) continue;
				map[ny][nx]={cur.first+cur.second/2+1, cur.second};
				pq.push({ny, nx});
			}

		}
		cout <<'#'<<t<<' '<< cnt<<'\n';
	}
}
