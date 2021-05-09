#include<cstdio>
int main(void){
	int x, y;
	scanf("%d %d", &x, &y);
	if(y>0&&x>0) printf("1");
	if(y>0&&x<0) printf("2");
	if(y<0&&x<0) printf("3");
	if(y<0&&x>0) printf("4");
}
