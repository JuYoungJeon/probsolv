#include <cstdio>

using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	int i=1;
	int ans=1;
	while(i<n){
		i+=ans*6;
		ans+=1;
	}
	printf("%d", ans);
}
