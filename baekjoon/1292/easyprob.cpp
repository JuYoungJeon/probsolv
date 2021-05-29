#include<cstdio>
using namespace std;
int main(void){
	int a, b;
	scanf("%d %d", &a, &b);
	int ans=0;
	int nu=1;
	int iter=0;
	for(int i=1; i<1001; i++){
		iter+=1;
		if(i>=a && i<=b){
			ans+=nu;
		}
		if(i>b)break;
		if(iter==nu) {iter=0; nu+=1;}
	}
	printf("%d", ans);
}
