#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int tree[100001];
vector<int> edges[100001];
int main(void){
	int n;
	scanf("%d", &n);
	tree[1]=-1;
	for(int i=1; i<n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	queue<int> layer;
	layer.push(1);
	while(!layer.empty()){
		int l = layer.front();
		layer.pop();
		for(auto &c: edges[l]){
			if(tree[c]!=0)continue;
			tree[c]=l;
			layer.push(c);
		}
	}
	for(int i=2; i<=n; i++)
		printf("%d\n", tree[i]);
}
