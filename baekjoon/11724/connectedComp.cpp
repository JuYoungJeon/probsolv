#include<iostream>
#include <vector>
#include<cstdio>

using namespace std;
int visited[1001]={0};
int groupIdx[1001]={0};

void makeGroup(int v, vector<int> edges[1001], int gIdx){
	visited[v]=true;
	groupIdx[v]=gIdx;
	for (int i=0; i<edges[v].size();i++){
		if(visited[edges[v][i]]==false)
			makeGroup(edges[v][i], edges, gIdx);
	}
}



int getConnectedComp(int n, vector<int> edges[1001]){
	int num=0;
	for(int i=1; i<=n; i++){
		if (edges[i].empty()) {num++; continue;}
		if (visited[i]==false){
			if(groupIdx[i]==0) num++;
			makeGroup(i, edges, num);
		}

	}

	return num;
}

int main(void){
	int n, m;
	cin >> n >> m;

	vector<int> edges[1001];
	for (int i=0; i< m; i++){
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	cout << getConnectedComp(n, edges);
}
