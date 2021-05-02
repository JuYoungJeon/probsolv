#include<cstdio>
int main(void){
	int n, c;
	scanf("%d %d", &n, &c);
	c=c>n-c?n-c:c;
	if(c==0) {printf("1"); return 0;}
	int ans=1;
	int div=1;
	for(int i=0; i<c; i++){
		ans*=(n-i);
		div*=(c-i);
	}
	printf("%d", ans/div);
	
}
