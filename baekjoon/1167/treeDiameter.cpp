#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int visited[100001];
int dp[100001];
int visitedLeaf[100001];
vector<pair<int, int> > edges[100001];
int leaf[100001];
int node;

void dfs(int s){
	if(leaf[s])visitedLeaf[s]=s;
	for(auto& c: edges[s]){
		if(!visited[c.first]) {
			visited[c.first]=1;
			dfs(c.first);
			int tmp=dp[c.first]+c.second;
			if(dp[s]<tmp){
				dp[s]=tmp;
				visitedLeaf[s]=visitedLeaf[c.first];
			}
		}
	}
}

int main(void){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int t;
		scanf("%d", &t);
		int cnt=0;
		while(1){
			int cn;
			scanf("%d", &cn);
			if(cn==-1)	break;
			int d;
			scanf("%d", &d);
			edges[t].push_back(make_pair(cn, d));
			cnt+=1;
		}
		if(edges[t].size()==1) leaf[t]=1;
		node=t;
	}
	visited[node]=1;
	dfs(node);
	node=visitedLeaf[node];
	memset(visited, 0, sizeof(visited));
	memset(dp, 0, sizeof(dp));
	memset(visitedLeaf, 0, sizeof(visited));
	visited[node]=1;
	dfs(node);
	printf("%d", dp[node]);
}
//Note: tree 지름 찾기
// random한노드에서 가장 먼노드찾기
// 해당 노드에서 가장 먼노드 찾기
