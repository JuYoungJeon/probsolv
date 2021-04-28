#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(void){
	int tc;
	scanf("%d", &tc);
	for(int i=0; i<tc; i++){
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		double dist=sqrt(pow(abs(x2-x1), 2)+pow(abs(y2-y1), 2));
		if(abs(r2-r1)>dist) printf("0\n");
		else if(x1==x2&&y1==y2&&r1==r2) printf("-1\n"); 
		else if(dist>r2+r1) printf("0\n");
		else if(abs(r2-r1)==dist) printf("1\n");
		else if(dist==r2+r1) printf("1\n");
		else printf("2\n");
	}

}
//Note: 내접/원이 다른원안에 있을때 abs(r2-r1)와 dist를 비교, 교점이 2개일때는 r1-r2<dist<r1+r2
