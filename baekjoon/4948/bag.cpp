#include <cstdio>
#include <cstring>
using namespace std;
int main(void){
	int n;
	int isPrime[246920];
	memset(isPrime, 0, sizeof(isPrime));
	int i=2;
	while(i<=246920) {
		int j=2;
		while(j*i<=246920){isPrime[j*i]=-1; j+=1;}
		i+=1;
	}
	while(1){
		scanf("%d", &n);
		if(n==0) break;
		int ans=0;
		for(int i=n+1; i<=2*n; i++){
			if(!isPrime[i]) ans+=1;
		}
		printf("%d\n", ans);
	}
}
