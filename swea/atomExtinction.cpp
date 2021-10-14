#include<iostream>
#include<vector>
#define BASE 1000

using namespace std;

int dir[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;
	for(int test_case = 1; test_case<=T; test_case++){
		int map[2000][2000];
		int N; 
		vector<tuple<int, int, int, int>> atoms;
		cin >> N; 
		for(int i=1;i<=N; i++){
			int x, y, d, k;
			cin >> x >> y>> d>>k
			atoms.push_back({y-BASE, x+BASE, k, d});
			map[y-BASE][x+BASE]=i;
		}
		int rem= N;
		int ans=0;
		while(rem>0){
			for(int a =0; i<atoms.size(); i++){
				if(atoms[a].first==-1&&atoms[a].second==-1) continue;
				int ny = get<0>(atoms[a])+dir[d][0];
				int nx = get<1>(atoms[a])+dir[d][1];
				if(!map[ny][nx]) {
					if(dir[get<2>(atoms[a])][0]*-1==dir[get
				}
			}
		}
	}
}
