#include <cstdio>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	int ans=0;
	for(int i=0; i<n; i++){
		int num;
		scanf("%d", &num);
		if(num<=1) continue;
		bool isprime=true;
		for(int j=2; j<num-1; j++){
			if(num%j==0) { isprime=false; break; }
		}
		if(isprime) ans+=1;
	}
	printf("%d", ans);
}
