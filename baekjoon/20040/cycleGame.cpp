#include<cstdio>
using namespace std;
int par[500000];
int find(int a){
	if(par[a]==a) return par[a];
	return par[a]=find(par[a]);
}

void uni(int a, int b){
	int para=find(a);
	int parb=find(b);
	if(para!=parb){
		par[parb]=para;
	}
}

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n; i++) par[i]=i;
	int ans=0;
	for(int i=1;i<=m; i++){
		int  a, b;
		scanf("%d %d", &a, &b);
		if(find(a)!=find(b)) {
			uni(a, b);
		}else{
			printf("%d", i);
			return 0;
		}
	}
	printf("0");

}
//NOTE: union-find할때 유의할점은 union에서 부모끼리 union하는 것임!!!
