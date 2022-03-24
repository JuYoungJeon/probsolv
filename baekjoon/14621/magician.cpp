#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>

using namespace std;

int par[1001];
vector<tuple<int, int, int>> edges;
int wm[1001];

int getPar(int a){
	if(a==par[a]) return par[a];
	return par[a]=getPar(par[a]);
}

bool uni(int a, int b){
	int pa = getPar(a);
	int pb = getPar(b);
	if(pa==pb) return false;
	par[pb]=par[pa];
	return true;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int ans=0;
	cin >> N>>M;
	for(int i=1;i<=N; i++){
		char c;
		cin >> c;
		if(c=='W') wm[i]=0;
		else wm[i]=1;
	}
	for(int i=0;i<M; i++){
		int a, b, c;
		cin >> a>>b>>c;
		edges.push_back({c, a, b});
	}
	sort(edges.begin(), edges.end());
	for(int i=1; i<=N; i++) par[i]=i;
	for(int i=0;i<M; i++){
		if(!(wm[get<1>(edges[i])]^wm[get<2>(edges[i])])) continue;
		if(uni(get<1>(edges[i]), get<2>(edges[i]))) ans+= get<0>(edges[i]);
	}
	for(int i=2; i<=N; i++){
		if(getPar(i-1)!=getPar(i)) ans=-1;
	}
	cout << ans;
}
