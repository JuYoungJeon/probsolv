#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int visited[10001];
vector<int> graph[10001];
vector<int> graphT[10001];
vector<vector<int> > scc;
stack<int> st;

void dfs(int idx){
	visited[idx]=1;
	for(auto & e: graph[idx]){
		if(visited[e]) continue;
		dfs(e);
	}
	st.push(idx);
}

void dfsRev(int idx, int sccIdx){
	visited[idx]=1;
	scc[sccIdx].push_back(idx);
	for(auto &e: graphT[idx]){
		if(visited[e]) continue;
		dfsRev(e, sccIdx);
	}
}

bool cmp(vector<int> a, vector<int> b){
	return a[0]<b[0];
}

int main(void){
	int V, E;
	scanf("%d %d", &V, &E);
	for(int i=0;i<E; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graphT[b].push_back(a);
	}
	memset(visited, 0, sizeof(visited));
	for(int i=1; i<=V; i++) if(!visited[i]) dfs(i);
	memset(visited, 0, sizeof(visited));
	int sccIdx=0;
	while(!st.empty()){
		int next = st.top();
		st.pop();
		if(visited[next]) continue;
		scc.push_back(vector<int>());
		dfsRev(next, sccIdx);
		sccIdx+=1;
	}
	printf("%d\n", sccIdx);
	for(int i=0; i<sccIdx; i++){
		sort(scc[i].begin(), scc[i].end());
	}
	sort(scc.begin(), scc.end(), cmp);
	for(int i=0; i<sccIdx; i++){	
		for(auto & j: scc[i]) printf("%d ", j);
		printf("-1\n");
	}
}
