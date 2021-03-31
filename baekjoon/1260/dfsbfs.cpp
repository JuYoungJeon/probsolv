#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool checkdfs[1001]={0};
bool checkbfs[1001]={0};
queue<int> q;

vector<int> bfs(int startIdx, vector<vector<int> > edges, vector<int> bfsOrder){
	checkbfs[startIdx]=true;
	q.push(startIdx);
	while(!q.empty()){
		int n= q.front();
		q.pop();
		bfsOrder.push_back(n);
		sort(edges[n].begin(), edges[n].end());
		for(int i=0; i<edges[n].size(); i++){
			if(checkbfs[edges[n][i]]==false){
				checkbfs[edges[n][i]]=true;
				q.push(edges[n][i]);
			}
		}
	}
	return bfsOrder;

}
vector<int> dfs(int startIdx, vector<vector<int> > edges, vector<int> dfsOrder){
	checkdfs[startIdx]=true;
	dfsOrder.push_back(startIdx);
	sort(edges[startIdx].begin(), edges[startIdx].end());
	for (int i=0; i< edges[startIdx].size(); i++){
		if(checkdfs[edges[startIdx][i]]==0)
			dfsOrder=dfs(edges[startIdx][i], edges, dfsOrder);
	}
	return dfsOrder;
}

int main(){
	int n, m, startIdx;
	scanf("%d %d %d", &n, &m, &startIdx);

	vector<vector<int> > edges(n+1, vector<int>());
	for(int i=0; i< m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<int> dfsOrder, bfsOrder;
	dfsOrder= dfs(startIdx, edges, dfsOrder);
	bfsOrder = bfs(startIdx, edges, bfsOrder);
	for(int i=0; i<dfsOrder.size(); i++){
		cout << dfsOrder[i];
		if (i!= dfsOrder.size()-1) cout << ' ';
		else cout << '\n';
	}
	for(int i=0; i<bfsOrder.size(); i++){
		cout << bfsOrder[i];
		if( i!= bfsOrder.size()-1) cout << ' ';
	}
}
