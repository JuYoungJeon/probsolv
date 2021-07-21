#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int visited[100001];
int scc[100001];
vector<int> dom[100001];
vector<int> domT[100001];
stack<int> st;
int innode[100001];

void dfs(int idx){
	visited[idx]=1;
	for(auto& node: dom[idx]){
		if(visited[node]) continue;
		dfs(node);
	}
	st.push(idx);
}
void backTrack(int curr, int idx){
	visited[curr]=1;
	scc[curr]=idx;
	for(auto & next: domT[curr]){
		if(!visited[next]) {
			backTrack(next, idx);
		}else if(scc[curr]!=scc[next]){
			innode[scc[curr]]+=1;
		}
	}
}

int main(void){
	int TC; 
	scanf("%d", &TC);
	for(int t=0; t<TC; t++){
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i=0; i<=n; i++){
			dom[i].clear();
			domT[i].clear();
		}
		memset(scc, 0, sizeof(scc));
		memset(visited, 0, sizeof(visited));
		memset(innode, 0, sizeof(innode));
		for(int j=0; j<m; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			dom[x].push_back(y);
			domT[y].push_back(x);
		}
		for(int i=1; i<=n; i++) if(!visited[i])dfs(i);
		memset(visited, 0, sizeof(visited));
		int idx=1;
		while(!st.empty()){
			int next= st.top();
			st.pop();
			if(visited[next]) continue;
			backTrack(next, idx);
			idx+=1;
		}
		int ans=0;
		for(int i=1; i<idx; i++){
			if(!innode[i])ans+=1;
		}
		printf("%d\n", ans);
	}
}
