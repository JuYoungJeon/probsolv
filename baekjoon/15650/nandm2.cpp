#include<cstdio>
int pool[9];
void perm(int sel,int ch, int n, int m){
	if(sel==m){
		for(int i=0; i<m; i++){
			printf("%d ", pool[i]);
		}
		printf("\n");
		return;
	}
	for(int i=ch; i<=n; i++){
		pool[sel]=i;
		perm(sel+1, i+1, n, m);
	}
}
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	perm(0, 1, n, m);
}
