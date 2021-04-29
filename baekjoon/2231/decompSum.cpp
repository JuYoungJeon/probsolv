#include<cstdio>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	int ans=0;
	for(int i=1; i<=n; i++){
		int sum=i;
		int j=i;
		while(j!=0){
			sum+=j%10;
			j/=10;
		}
		if(sum==n) {
			ans=i;
			break;
		}
	}
	printf("%d", ans);
}
