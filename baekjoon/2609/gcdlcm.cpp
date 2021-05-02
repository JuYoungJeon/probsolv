#include<cstdio>
int main(void){
	int a, b;
	scanf("%d %d", &a, &b);
	int gcd=a<b?a:b;
	int lcm=a>b?a:b;
	int i=1;
	while(gcd>0){
		if(a%gcd==0&&b%gcd==0) break;
		gcd--;
	}
	while(lcm*i<a*b){
		if(lcm*i%a==0&&lcm*i%b==0) break;
		i+=1;
	}
	lcm*=i;
	printf("%d\n%d", gcd, lcm);

}
