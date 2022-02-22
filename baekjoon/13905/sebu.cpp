#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

int N, M;
int maxCarr[100001];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(maxCarr, 0, sizeof(maxCarr));
	int s, e;
	vector<pair<int, int>> dist[100001];
	cin >> N >> M;
	cin >> s >> e;

	for(int i=0;i<M; i++){
		int a, b, c;
		cin >> a>> b >> c;
		dist[a].push_back({b, c});
		dist[b].push_back({a, c});
	}
	queue<int> q;
	q.push(s);
	maxCarr[s]=1000000;
	while(!q.empty()){
		int c = q.front();
		q.pop();
		for(auto n: dist[c]){
			if(maxCarr[n.first]>=min(maxCarr[c], n.second)) continue;
			maxCarr[n.first]=min(maxCarr[c], n.second);
			q.push(n.first);
		}
	}
	cout << maxCarr[e];
}
