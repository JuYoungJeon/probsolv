#include<cstdio>
#include<algorithm>
using namespace std;
int tree[100001];
int find(int x){
	if(x==tree[x]) return x;
	return tree[x]=find(tree[x]);
}
bool unionTree(int x){
	int px=find(x);
	if(px==0) return false;
	tree[px]=px-1;
	return true;
}
int main(void){
	int G, P;
	scanf("%d", &G);
	scanf("%d", &P);
	int ans=0;
	bool input=true;
	for (int i=1; i<=G; i++) tree[i]=i;
	for(int i=0; i<P; i++){
		int gi;
		scanf("%d", &gi);
		if(input) {
			if(unionTree(gi)) ans+=1;
			else input=false;
		}
	}
	printf("%d", ans);
}
//disjoint set으로 풀기
