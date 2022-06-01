#include <bits/stdc++.h>

using namespace std;

pair<int, int> dist[1001];
int company[1001];

struct cmp{
	bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
		if(get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
		return get<1>(a) > get<1>(b);
	}
};

int main(void){
	int N, M;
	cin >> N >> M;
	for(int i=0;i<N; i++){
		cin >> company[i];
		dist[i]={1000*1000, 1000*1000};
	}
	vector<tuple<int, int, int>> edges[1001];
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			int t;
			cin >> t;
			if(t>0) edges[i].push_back({company[i]^company[j], t, j});
		}
	}
	dist[0]={0, 0};
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> q;
	q.push({0, 0, 0});
	while(!q.empty()){
		int d1 = get<0>(q.top());
		int d2 = get<1>(q.top());
		int idx = get<2>(q.top());
		q.pop();
		if(M==idx) break;
		if(get<0>(dist[idx]) != d1) continue;
		if(get<0>(dist[idx]) == d1 && get<1>(dist[idx]) != d2) continue;
		for(auto e:edges[idx]){
			int ed1 = get<0>(e);
			int ed2 = get<1>(e);
			int eidx = get<2>(e);
			if(ed1+d1 < dist[eidx].first || (ed1+d1==dist[eidx].first && ed2+d2 < dist[eidx].second)){
				dist[eidx].first = ed1 + d1;
				dist[eidx].second = ed2 + d2;
				q.push({dist[eidx].first, dist[eidx].second, eidx});
			}
		}
	}
	cout << dist[M].first<<' '<<dist[M].second;

}
