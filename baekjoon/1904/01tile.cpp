#include<cstdio>
#include<cstring>
long long d[1000001];
int getNtile(int n){
	if(d[n]) return d[n];
	d[n]=getNtile(n-1)+getNtile(n-2);
	d[n]%=15746;
	return d[n];
}
int main(void){
	int n;
	scanf("%d", &n);
	memset(d, 0, sizeof(d));
	d[1]=1;
	d[2]=2;
	printf("%d", getNtile(n));
}
