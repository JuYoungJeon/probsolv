#include<iostream>
#include<cstring>
using namespace std;
int fare[4];
int usage[12];
int dayM[12];
int dfs(int cur){
	if(cur>11) return 0;
	int ret = 3000*12;
	ret = min(ret, dfs(cur+1)+min(dayM[cur],fare[1]));
	ret = min(ret, dfs(cur+3)+fare[2]);
	return ret;
}
int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++){
		for(int i=0;i<4; i++) cin >> fare[i];
		for(int i=0;i<12; i++) cin >> usage[i];
		int minCost=fare[3];
		for(int i=0;i<12; i++){
			dayM[i]=fare[0]*usage[i];
		}
		int cost=0;
		cout <<'#'<<test_case<<' '<< min(fare[3], dfs(0))<<'\n';
	}
}
