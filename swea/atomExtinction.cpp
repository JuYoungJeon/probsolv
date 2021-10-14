#include<iostream>
#include<cstring>
#include<tuple>
#include<vector>
#define BASE 1000

using namespace std;

int dir[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int map[2002][2002];

int main(void){
	int T;
	cin >> T;
	for(int test_case = 1; test_case<=T; test_case++){
		int N; 
		memset(map, 0, sizeof(map));
		vector<tuple<int, int, int, int>> atoms;
		cin >> N; 
		for(int i=1;i<=N; i++){
			int x, y, d, k;
			cin >> x >> y>> d>>k;
			atoms.push_back({BASE-y, x+BASE, d, k});
			map[BASE-y][x+BASE]=i;
		}
		int rem= N;
		int ans=0;
		while(rem>0){
			for(int a =0; a<atoms.size(); a++){
				if(get<0>(atoms[a])==-1&&get<1>(atoms[a])==-1) continue;
				int ny = get<0>(atoms[a])+dir[get<2>(atoms[a])][0];
				int nx = get<1>(atoms[a])+dir[get<2>(atoms[a])][1];
				map[get<0>(atoms[a])][get<1>(atoms[a])]=0;
				if(ny<0||nx<0||ny>=2001||nx>=2001){
					get<0>(atoms[a])=-1, get<1>(atoms[a])=-1;
					rem-=1; continue;
				}
				if(!map[ny][nx]) {
					int cd = get<2>(atoms[a]);
					int td = get<2>(atoms[map[ny][nx]]);
					if(dir[cd][0]*-1==dir[td][0]&&dir[cd][1]*-1==dir[td][1]){
						rem-=2;
						ans+=get<3>(atoms[a]);
						ans+=get<3>(atoms[map[ny][nx]]);
						cout << get<3>(atoms[a]) << ' '<<get<3>(atoms[map[ny][nx]])<<'\n';
						cout << a <<' '<<map[ny][nx]<<'\n';
						get<0>(atoms[a])=-1, get<1>(atoms[a])=-1;
						get<0>(atoms[map[ny][nx]])=-1, get<1>(atoms[map[ny][nx]])=-1;
						map[ny][nx]=0;
					}else{
						get<0>(atoms[a])=ny;
						get<1>(atoms[a])=nx;
					}
				}else{
					get<0>(atoms[a])=ny;
					get<1>(atoms[a])=nx;
				}
			}
			for(int a=0; a<atoms.size(); a++){
				int y = get<0>(atoms[a]);
				int x = get<1>(atoms[a]);
				if(y==-1&& x==-1) continue;
				if(map[y][x]!=0&&map[y][x]<a){
					get<0>(atoms[a])=-1, get<1>(atoms[a])=-1;
					get<0>(atoms[map[y][x]])=-1, get<1>(atoms[map[y][x]])=-1;
					ans+=get<3>(atoms[a]);
					ans+=get<3>(atoms[map[y][x]]);
					cout << get<3>(atoms[a]) <<' '<<get<3>(atoms[map[y][x]])<<'\n';
					cout << a<<' '<<map[y][x]<<'\n';
					map[y][x]=0;
					rem-=2;
				}else
					map[y][x]=a;
			}
		}
		cout << ans;
	}
}
