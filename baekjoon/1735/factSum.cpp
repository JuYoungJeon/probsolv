#include<cstdio>
using namespace std;

int gcd(int a, int b){
	if(a==0) return b;
	return gcd(b%a, a);
}

int main(void){
	int a, b;
	int c, d;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);
	int div = gcd(a*d+b*c, b*d);
	printf("%d %d", (a*d+b*c)/div, (b*d)/div);
}
