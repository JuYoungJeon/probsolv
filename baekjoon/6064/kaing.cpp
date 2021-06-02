#include<cstdio>
using namespace std;
int gcb(int x, int y){
	if(y==0) return x;
	else return gcb(y, x%y);
}
int main(void){
	int tc;
	scanf("%d", &tc);
	for(int t=0; t<tc; t++){
		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);
		int maxV= gcb(m, n);
		maxV=m*n/maxV;
		int res = -1;
		int next = 0;
		if (m>n){
			while(m*next+x<=maxV){
				if((m*next+x-y)%n==0){res=m*next+x; break;}
				next+=1;
			}
		}else{
			while(n*next+y<=maxV){
				if((n*next+y-x)%m==0){ res=n*next+y; break;}
				next+=1;
			}
		}
		printf("%d\n", res);
	}
}
