#include<cstdio>
using namespace std;
int main(void){
	int x1, x2, x3, y1, y2, y3;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	double s=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
	s/=2.0;
	if(s>0) printf("1");
	else if(s==0) printf("0");
	else printf("-1");
}
