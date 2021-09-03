#include<iostream>
#include<tuple>
#include<queue>
#include<vector>
using namespace std;
#define tiii tuple<int, int, int>
#define pii pair<int, int>
int par[1001];

int find(int a){
	if(a==par[a]) return a;
	else return par[a]=find(par[a]);
}

bool uni(int a, int b){
	int pa = find(a);
	int pb = find(b);
	if(pa==pb) return false;
	par[pb]=pa;
	return true;
}
struct cmp{ bool operator()(tiii a, tiii b){ return get<0>(a) > get<0>(b); } };

int main(void){
	int n, m;
	cin >> n >> m;
	vector<pii> edges[1001];
	priority_queue<tiii, vector<tiii>, cmp> pq;
	for(int i=1; i<=n; i++) par[i]=i;
	for(int i=0;i<m; i++){
		int a, b, c;
		cin >> a>>b>> c;
		pq.push(make_tuple(c, a, b));
	}
	int ans=0;
	while(!pq.empty()){
		tiii curr = pq.top();
		pq.pop();
		if(uni(get<1>(curr), get<2>(curr))){
			ans+=get<0>(curr);
		}
	}
	cout << ans;
}
