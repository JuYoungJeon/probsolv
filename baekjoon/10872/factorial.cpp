#include <cstdio>
using namespace std;
int fact[12];

int main(void){
	int n;
	scanf("%d", &n);
	int ans=1;
	for(int i=2; i<=n; i++)
		ans*=i;
	printf("%d", ans);
}
