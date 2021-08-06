#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int acq[1001];
int visited[1001];

vector<int> g[1001];
bool dfs(int idx){
	for(auto& e: g[idx]){
		if(visited[e]) continue;
		visited[e]=true;
		if(acq[e]==0||dfs(acq[e])){
			acq[e]=idx;
			return true;
		}
	}
	return false;
}

int main(void){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	for(int i=1;i<=n; i++){
		int nu;
		scanf("%d", &nu);
		for(int j=0; j<nu; j++){
			int idx;
			scanf("%d", &idx);
			g[i].push_back(idx);
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		memset(visited, 0, sizeof(visited));
		if(dfs(i)) ans+=1;
	}
	for(int i=0; i<k;i++){
		bool isNew=false;
		for(int j=1; j<=n; j++){
			memset(visited, 0, sizeof(visited));
			if(dfs(j)){ ans+=1; isNew=true; break;} 
		}
		if(!isNew)break;
	}
	printf("%d", ans);
}
