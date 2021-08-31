#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;

#define tiii tuple<int, int, int>

struct cmpTuple{ bool operator()(tiii a, tiii b){ return get<0>(a) > get<0>(b);}};

int par[100001];
priority_queue<tiii, vector<tiii>, cmpTuple> pq;

int find(int a){
	if(par[a]==a) return a;
	else return par[a]=find(par[a]);
}

bool uni(int a, int b){
	int pa = find(a);
	int pb = find(b);
	if(pa!=pb){
		par[pb]=pa;
		return true;
	}else return false;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m; i++){
		int a, b, c;
		cin >> a>> b>> c;
		pq.push(make_tuple(c, a, b));
	}
	if(m==2) {cout << 0; return 0;}
	for(int i=1; i<=n; i++) par[i]=i;
	int maxEdge;
	int ans=0;
	while(!pq.empty()){
		tiii curr = pq.top();
		pq.pop();
		if(uni(get<1>(curr), get<2>(curr))){
			ans+=get<0>(curr);
			maxEdge=get<0>(curr);
		}
	}
	cout << ans-maxEdge;
}
