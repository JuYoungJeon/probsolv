#include<cstdio>
using namespace std;
int p[9];
void perm(int sel, int ch, int n, int m){
	if(sel==m){
		for(int i=0; i<m; i++){
			printf("%d ", p[i]);
		}
		printf("\n");
		return ;
	}
	for(int i=ch; i<=n; i++){
		p[sel]=i;
		perm(sel+1, i, n, m);
	}
}

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	perm(0, 1, n, m);
}
