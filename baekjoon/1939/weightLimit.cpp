#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

int minWeight[10001];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(minWeight, 0, sizeof(minWeight));

	int N, M; 
	cin >> N>> M;
	vector<pair<int, int>> bridge[10001];
	for(int i=0;i<M;i++){
		int a, b, c;
		cin >> a>> b>>c;
		bridge[a].push_back({c, b});
		bridge[b].push_back({c, a});
	}
	int s, e;
	cin >> s>>e;
	// s->idx minWeight, idx
	minWeight[s]=1000000000;
	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
	for(int i=0; i<N; i++) {
		if(i+1==s) pq.push({1000000000, s});
		else pq.push({0, i+1});
	}
	while(!pq.empty()){
		pair<int, int> c = pq.top();
		pq.pop();
		if(c.second==e) break;
		for(auto n: bridge[c.second]){
			if(minWeight[n.second]>=min(minWeight[c.second], n.first)) continue;
			minWeight[n.second]=min(minWeight[c.second], n.first);
			pq.push({minWeight[n.second], n.second});
		}
	}
	cout << minWeight[e];
}
