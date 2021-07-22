#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
vector<int> graph[1001];
int visited[1001];
int assigned[1001];

bool dfs(int x){
	for(int e:graph[x]){
		if(visited[e]) continue;
		visited[e]=1;
		if(assigned[e]==0||dfs(assigned[e])) {
			assigned[e]=x;
			return true;
		}
	}
	return false;
}

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		int w; 
		scanf("%d", &w);
		for(int j=0; j<w; j++){
			int t;
			scanf("%d", &t);
			graph[i].push_back(t);
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		memset(visited, 0, sizeof(visited));
		if(dfs(i)) ans+=1;
	}
	printf("%d", ans);
}
