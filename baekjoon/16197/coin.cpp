#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int dir[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char map[20][20];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	pair<int, int> coin1={-1, -1};
	pair<int, int> coin2={-1, -1};
	for(int i=0;i<N; i++){
		for(int j=0;j<M; j++){
			cin >> map[i][j];
			if(map[i][j]=='o'){
				if(coin1.first==-1){
					coin1.first=i;
					coin1.second=j;
				}else{
					coin2.first=i;
					coin2.second=j;
				}
				map[i][j]='.';
			}
		}
	}
	queue<tuple<pair<int, int>, pair<int, int>, int>> q;
	q.push({coin1, coin2, 0});
	while(!q.empty()){
		pair<int, int> c1 = get<0>(q.front());
		pair<int, int> c2 = get<1>(q.front());
		int as = get<2>(q.front());
		q.pop();
		if(as>=10) continue;
		for(int i=0;i<4; i++){
			int c1y = c1.first+dir[i][0];
			int c2y = c2.first+dir[i][0];
			int c1x = c1.second+dir[i][1];
			int c2x = c2.second+dir[i][1];
			int cntOut=0;
			if(c1y<0||c1y>=N||c1x<0||c1x>=M) cntOut+=1;
			if(c2y<0||c2y>=N||c2x<0||c2x>=M) cntOut+=1;
			if(cntOut==1) {
				cout << as+1;
				return 0;
			}
			if(cntOut==2) continue;
			if(map[c1y][c1x]=='#'){
				c1y=c1.first;
				c1x=c1.second;
			}
			if(map[c2y][c2x]=='#'){
				c2y=c2.first;
				c2x=c2.second;
			}
			q.push({{c1y, c1x}, {c2y, c2x}, as+1});
		}
	}
	cout << -1;
}
