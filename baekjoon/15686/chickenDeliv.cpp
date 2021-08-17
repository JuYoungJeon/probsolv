#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define pii pair<int, int>

int town[50][50];
int cd[50][50];
int dir[4][2]={{1,0},{-1,0}, {0,-1},{0,1}};
vector<pii> ch;
vector<pii> home;
int getChickenDist(int n, vector<pii> c){
	int dist=0;
	for(auto& h: home){
		memset(cd, -1, sizeof(cd));
		int mindist=n*n;
		for(auto& b: c){
			mindist=min(mindist, (abs(h.first-b.first)+abs(h.second-b.second)));
		}
		dist+=mindist;
	}
	return dist;
}

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &town[i][j]);
			if(town[i][j]==2) ch.push_back({i, j});
			if(town[i][j]==1) home.push_back({i, j});
		}
	}
	vector<int> comb(ch.size(), 0);
	for(int i=0; i<m; i++){
		comb[i]=1;
	}
	sort(comb.begin(), comb.end());
	int ans=50*2*n;
	do{
		vector<pii> c;
		for(int i=0;i<ch.size(); i++){
			if(comb[i]==1){
				c.push_back(ch[i]);
			}
		}
		ans=min(ans, getChickenDist(n, c));
	}while(next_permutation(comb.begin(), comb.end()));
	printf("%d", ans);
}
