#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;

stack<int> st;
int scc[100001];
int visited[100001];
int innode[100001];
vector<int> graph[100001];
vector<int> graphT[100001];

void dfs(int idx){
	visited[idx]=1;
	for(int e: graph[idx]){
		if(visited[e]) continue;
		dfs(e);
	}
	st.push(idx);
}

void dfs2(int idx, int scIdx){
	visited[idx]=1;
	scc[idx]=scIdx;
	for(int e: graphT[idx]){
		if(!visited[e]) {
			dfs2(e, scIdx);
		}else if(scc[idx]!=scc[e])
			innode[scc[idx]]+=1;
	}
}

int main(void){
	int tc;
	scanf("%d", &tc);
	for(int t=0; t<tc; t++){
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i=0;i<=n; i++){
			graph[i].clear();
			graphT[i].clear();
		}
		memset(visited, 0, sizeof(visited));
		memset(scc, 0, sizeof(scc));
		memset(innode, 0, sizeof(innode));
		for(int i=0; i<m; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graphT[b].push_back(a);
		}
		for(int i=0; i<n; i++){
			if(!visited[i]) dfs(i);
		}
		memset(visited, 0, sizeof(visited));
		int scidx=0;
		while(!st.empty()){
			int next =st.top();
			st.pop();
			if(visited[next]) continue;
			dfs2(next, scidx);
			scidx+=1;
		}
		vector<int> ansIdx;
		for(int i=0; i<scidx; i++){
			if(innode[i]==0) ansIdx.push_back(i);
		}
		if(ansIdx.size()!=1) {printf("Confused\n\n"); continue;}
		for(int i=0; i<n; i++){
			if(ansIdx[0]==scc[i]) printf("%d\n", i);
		}
		printf("\n");
	}
}
