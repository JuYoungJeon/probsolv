#include <cstdio>
using namespace std;
int main(void){
	while(1){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a==0&&b==0&&c==0) break;
		bool accurate=false;
		if(a>b&& a>c){
			if(a*a==b*b+c*c) accurate=true;
		}
		if(b>a&& b>c){
			if(b*b==a*a+c*c) accurate=true;
		}
		if(c>a &&c>b){
			if(c*c==a*a+b*b) accurate=true;
		}
		if(accurate) printf("right\n");
		else printf("wrong\n");
	}
}
