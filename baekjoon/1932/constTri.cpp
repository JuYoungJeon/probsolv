#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int tri[501][501];
int sum[501][501];
int main(void){
	int n;
	scanf("%d", &n);
	memset(tri, 0, sizeof(tri));
	memset(sum, 0, sizeof(sum));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			scanf("%d", &tri[i][j]);
		}
	}
	sum[1][1]=tri[1][1];
	for(int i=2; i<=n; i++){
		for(int j=1; j<=i; j++){
			if(j==1) sum[i][j]=sum[i-1][j]+tri[i][j];
			if(j==i) sum[i][j]=sum[i-1][j-1]+tri[i][j];
			else sum[i][j]=max(sum[i-1][j], sum[i-1][j-1])+tri[i][j];
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++)
		ans=max(ans, sum[n][i]);
	printf("%d", ans);
}
