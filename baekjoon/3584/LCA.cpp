#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#define MAX_SIZE 10001
using namespace std;

vector<int> graph[MAX_SIZE];
int ac[MAX_SIZE][30];
int depth[MAX_SIZE];
int visited[MAX_SIZE];
int rt[MAX_SIZE];

int max_level;

void getTree(int n, int c, int p){
	if (visited[c]) return;
	visited[c]=1;
	depth[c]=depth[p]+1;
	ac[c][0]=p;
	max_level=(int)floor(log2(MAX_SIZE));
	for(int i=1; i<=max_level; i++){
		int tmp = ac[c][i-1];
		ac[c][i]=ac[tmp][i-1];
	}
	int len=graph[c].size();
	for(int i=0; i<len; i++){
		int tmp = graph[c][i];
		if(tmp!=p) getTree(n, tmp, c);
	}
}

int lca(int n, int a, int b){
	if(depth[a]!=depth[b]){
		if(depth[a]>depth[b]) swap(a, b);
		for(int i=max_level; i>=0; i--) {
			if(depth[a]<=depth[ac[b][i]])b=ac[b][i];
		}
	}
	int lca=a;
	if(b!=a){
		for(int i=max_level; i>=0; i--){
			if(ac[a][i]!=ac[b][i]){
				a=ac[a][i];
				b=ac[b][i];
			}
			lca=ac[a][i];
		}
	}
	return lca;
}

int main(void){
	int tc;
	scanf("%d", &tc);
	for(int t=0; t<tc; t++){
		int n;
		scanf("%d", &n);
		memset(ac, 0, sizeof(ac));
		memset(depth, 0, sizeof(depth));
		memset(rt, 0, sizeof(rt));
		memset(visited, 0, sizeof(visited));
		for(int i=0; i<MAX_NODE; i++) graph[i].clear();
		for(int i=0; i<n-1; i++){
			int p, c;
			scanf("%d %d", &p, &c);
			graph[p].push_back(c);
			graph[c].push_back(p);
			rt[c]=p;
		}
		int root=0;
		for(int i=1; i<=n; i++) if(rt[i]==0) root=i;
		int a, b;
		scanf("%d %d", &a, &b);
		depth[0]=-1;
		getTree(n, root, 0);
		printf("%d\n", lca(n, a, b));

	}
}
