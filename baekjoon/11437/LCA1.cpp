#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define MAX_SIZE 50001
using namespace std;
int rt=1;

vector<int> graph[MAX_SIZE];
int AC[MAX_SIZE][30];
int depth[MAX_SIZE];
int visited[MAX_SIZE];

int max_level= (int)floor(log2(MAX_SIZE));

void makeTree(int N, int p, int c){
	if(visited[c]) return ;
	visited[c]=1;
	depth[c]=depth[p]+1;
	AC[c][0]=p;
	for(int i=1; i<=max_level; i++){
		int tmp=AC[c][i-1];
		AC[c][i]=AC[tmp][i-1];
	}
	int len = graph[c].size();
	for(int i=0; i<len; i++){
		if(graph[c][i]!=p)
			makeTree(N, c, graph[c][i]);
	}
}
int getLCA(int a, int b){
	if(depth[a]!=depth[b]){
		if(depth[a]>depth[b]) swap(a, b);
		for(int i=max_level; i>=0; i--){
			if(depth[a]<=depth[AC[b][i]]) b=AC[b][i];
		}
	}
	int ret =a;
	if(a!=b){
		for(int i=max_level; i>=0; i--){
			if(AC[a][i]!=AC[b][i]) {
				a=AC[a][i];
				b=AC[b][i];
			}
			ret = AC[a][i];
		}
	}
	return ret;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	depth[0]=-1;
	makeTree(N, 0, 1);
	int M;
	scanf("%d", &M);
	for(int i=0;i<M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", getLCA(a, b));
	}
}
