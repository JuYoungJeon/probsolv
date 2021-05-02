#include<cstdio>
//최대 공약수
int gcd(int a, int b){
	if(b!=0) return gcd(b, a%b);
	else return a;
}
int main(void){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		printf("%d\n", a*b/gcd(a,b));
	}
}
