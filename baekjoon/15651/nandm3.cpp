#include<cstdio>
using namespace std;
int p[8];
void perm(int n, int m, int sel){
	if(sel==m){
		for(int i=0; i<m; i++)
			printf("%d ", p[i]);
		printf("\n");
		return ;
	}
	for(int i=1; i<=n; i++){
		p[sel]=i;
		perm(n, m, sel+1);
	}
	return;
}
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	perm(n, m, 0);
}
