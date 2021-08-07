#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int visited[1001];
int job[1001];
vector<int> worker[1001];
bool dfs(int idx){
	for(auto& j: worker[idx]){
		if(visited[j]) continue;
		visited[j]=1;
		if(!job[j]|| dfs(job[j])){
			job[j]=idx;
			return true;
		}
	}
	return false;
}

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		int task;
		scanf("%d", &task);
		for(int j=0; j<task; j++){
			int t;
			scanf("%d",&t);
			worker[i].push_back(t);
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		memset(visited, 0, sizeof(visited));
		if(dfs(i)) ans+=1;
		memset(visited, 0, sizeof(visited));
		if(dfs(i)) ans+=1;
	}
	printf("%d", ans);
}
