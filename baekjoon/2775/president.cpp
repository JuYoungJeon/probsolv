#include <cstdio>
using namespace std;
int np[15][15];
int main(void){
	int tc;
	scanf("%d", &tc);
	for(int i=0; i<15; i++){
		np[0][i]=i;
		np[i][1]=1;
	}
	for(int i=0; i<tc; i++){
		int k, n;
		scanf("%d\n%d", &k, &n);
		for(int j=1;j<=k; j++){
			for(int l=2; l<=n; l++){
				np[j][l]=np[j-1][l]+np[j][l-1];
			}
		}
		printf("%d\n", np[k][n]);
	}
}


