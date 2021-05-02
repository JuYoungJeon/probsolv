#include<cstdio>
int gcd(int a, int b){
	if(b!=0) return gcd(b, a%b);
	else return a;
}
int main(void){
	int n;
	int num[100];
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &num[i]);
	}
	for(int i=1; i<n; i++){
		int g=gcd(num[0], num[i]);
		printf("%d/%d\n", num[0]/g, num[i]/g);
	}
}
