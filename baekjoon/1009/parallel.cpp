#include<cstdio>
#include<cmath>
using namespace std;

int main(void){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int a, b;
		scanf("%d %d", &a, &b);
		int ans=1;
		while(b>0) {ans*=a; b--;ans%=10;}
		if(ans==0)ans=10;
		printf("%d\n", ans);
	}
}
