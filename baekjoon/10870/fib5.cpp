#include <cstdio>
#include <cstring>
using namespace std;
int f[21];
int fib(int n){
	if(f[n]!=-1) return f[n];
	f[n]=fib(n-1)+fib(n-2);
	return f[n];
}

int main(void){
	int n;
	scanf("%d", &n);
	memset(f, -1, sizeof(f));
	f[0]=0; f[1]=1;
	printf("%d", fib(n));
}
