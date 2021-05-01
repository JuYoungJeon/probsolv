#include<cstdio>
#include<algorithm>
using namespace std;
int main(void){
	int n; 
	scanf("%d", &n);
	int dist[100000];
	int cost[100000];
	for(int i=0; i<n-1; i++)
		scanf("%d", &dist[i]);
	for(int i=0; i<n; i++)
		scanf("%d", &cost[i]);
	long long minCost=0;
	for(int i=0; i<n-1; ){
		int nexti=i+1;
		long long bd=dist[i];
		for(int j=i+1; j<=n-1; j++){
			nexti=j;
			if(cost[i]>cost[j]) break;
			bd+=dist[j];
		}
		minCost+=bd*cost[i];
		i=nexti;
	}
	printf("%lld", minCost);
}
//Note: 모든 변수가 range 를 담을수 있는지 확인
