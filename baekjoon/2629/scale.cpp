#include<cstdio>
#include<algorithm>
using namespace std;
int dp[31][15001];
int res[15001];
int c[31];
void check(int N, int cnt, int w){
	if(cnt>N||dp[cnt][w]) return;
	dp[cnt][w]=true;
	check(N, cnt+1, w);
	check(N, cnt+1, w+c[cnt]);
	check(N, cnt+1, abs(w-c[cnt]));
}
int main(void){
	int N;
	scanf("%d", &N);

	for(int i=0; i<N; i++)
		scanf("%d", &c[i]);
	int t;
	scanf("%d", &t);
	int tc[7];
	for(int i=0; i<t; i++)
		scanf("%d", &tc[i]);
	check(N, 0, 0);
	for(int i=0; i<t; i++){
		if(tc[i]>15000) printf("N ");
		else if(dp[N][tc[i]]) printf("Y ");
		else printf("N ");
	}
}
