#include<cstdio>
#include<cstring>
using namespace std;
int graph[201][201];
long long dp[201][201];

int dir[2][2]={{1,0},{0,1}};

void getDP(int sx, int sy, int ex, int ey){
	for(int y=sy; y<=ey; y++){
		for(int x=sx; x<=ex; x++){
			if(y==sy&&x==sx) continue;
			dp[y][x]=(dp[y-1][x]+dp[y][x-1])%1000007;
		}
	}
}

int main(void){
	int w, h, x, y;
	scanf("%d %d", &w, &h);
	scanf("%d %d", &x, &y);

	dp[1][1]=1;
	getDP(1, 1, x, y);
	int tmp = dp[y][x];
	memset(dp, 0, sizeof(dp));
	dp[y][x]=tmp;
	getDP(x, y, w, h);
	printf("%lld", dp[h][w]);
}
