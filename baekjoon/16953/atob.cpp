#include<cstdio>
#include<algorithm>
using namespace std;
long long b;
int dfs(long long a, int minop){
	if(a>b) return -2;
	if(a==b) return minop;
	int mu=dfs(a*2, minop+1);
	int ad=dfs(a*10+1, minop+1);
	if(mu>0&&ad>0) return min(mu, ad);
	if(mu>0) return mu; 
	if(ad>0) return ad;
	return -2;
}

int main(void){
	long long a;
	scanf("%d %d", &a, &b);
	if(a==b) printf("1");
	else printf("%d", dfs(a,0)+1);
}
