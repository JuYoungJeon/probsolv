#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>

using namespace std;

int par[1001];
int dist[1001][1001];

int getPar(int n){
	if(par[n]==n) return par[n];
	else return par[n]=getPar(par[n]);
}

bool findPar(int a, int b){
	return (getPar(a)==getPar(b));
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin>> N;
	vector<tuple<int, int, int>> d;
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			cin >> dist[i][j];
		}
		par[i]=i;
	}
	for(int i=0;i<N; i++){
		for(int j=i+1; j<N; j++){
			d.push_back(make_tuple(dist[i][j],i,j));
		}
	}
	sort(d.begin(), d.end());
	long long ans=0;
	for(auto c: d){
		if(!findPar(get<1>(c), get<2>(c))){
			ans+=get<0>(c);
			par[getPar(get<2>(c))]=getPar(get<1>(c));
		}
	}
	cout << ans;
}
