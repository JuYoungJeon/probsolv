#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int visited[201];
int home[201];
vector<int> cows[201];
bool dfs(int idx){
	for(auto& h:cows[idx]){
		if(visited[h]) continue;
		visited[h]=1;
		if(home[h]==0||dfs(home[h])){
			home[h]=idx;
			return true;
		}
	}
	return false;
}
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n; i++){
		int nh;
		scanf("%d", &nh);
		for(int j=0;j<nh; j++){
			int t;
			scanf("%d", &t);
			cows[i].push_back(t);
		}
	}
	int ans=0;
	for(int i=1;i<=n; i++){
		memset(visited, 0, sizeof(visited));
		if(dfs(i))ans+=1;
	}
	printf("%d", ans);
}
