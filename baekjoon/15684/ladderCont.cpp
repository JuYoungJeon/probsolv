#include<cstdio>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
int ladder[11][31];

bool checkLadder(int n, int h){
	for(int i=1; i<=n; i++){
		int res=i;
		for(int j=1; j<=h; j++){
			res+=ladder[res][j];
		}
		if(res!=i) return false;
	}
	return true;
}
bool dfs(int n, int h, int y, int numlad, int k){
	if(k>numlad) return checkLadder(n, h);
	bool ret=false;
	for(int i=1; i<n ;i++){
		for(int j=y; j<=h; j++){
			if(ladder[i][j]==0&&ladder[i+1][j]==0) {
				ladder[i][j]=1; ladder[i+1][j]=-1;
				if(dfs(n, h, j, numlad, k+1)) return true;
				ladder[i][j]=0; ladder[i+1][j]=0;
			}
		}
	}
	return ret;
}
int main(void){
	int n, m, h;
	scanf("%d %d %d", &n, &m, &h);
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		ladder[b][a]=1;
		ladder[b+1][a]=-1;
	}
	if(checkLadder(n, h)) printf("0");
	else{
		int ans=-1;
		for(int i=1; i<=3; i++) if(dfs(n, h, 1, i, 1)){ ans=i; break;}
		printf("%d", ans);
	}
}
