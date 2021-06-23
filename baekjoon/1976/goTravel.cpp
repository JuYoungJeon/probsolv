#include<cstdio>
using namespace std;
int parent[201];
int graph[201][201];
int target[1000];
int find(int a){
	if(parent[a]==a) return a;
	return parent[a]=find(parent[a]);
}
void uni(int a, int b){
	int pa= find(a);
	int pb= find(b);
	if(pa!=pb){
		parent[pb]=pa;
	}
}

int main(void){
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i=0; i<n; i++) parent[i]=i;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &graph[i][j]);
			if(graph[i][j]) uni(i, j);
		}
	}
	for(int i=0; i<m; i++)
		scanf("%d", &target[i]);
	int fr=find(target[0]-1);
	bool ans=true;
	for(int i=1; i<m; i++){
		int nr=find(target[i]-1);
		if(fr!=nr) {ans=false; printf("NO"); break;}
	}
	if(ans) printf("YES");
}
