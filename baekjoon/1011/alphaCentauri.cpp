#include<cstdio>
using namespace std;

int main(void){
	int tc; 
	scanf("%d", &tc);
	for(int i=0; i<tc; i++){
		long long d1, d2;
		scanf("%lld %lld", &d1, &d2);
		long long num=1;
		long long lowerbound=1;
		long long j=1;
		while(lowerbound<d2-d1){
			if(num%2!=0)lowerbound=j*(j+1);
			else{
				lowerbound=(j*(j+1))+j+1;
				j+=1;
			}
			num+=1;
		}
		printf("%lld\n", num);
	}
}
//Note: timeout caused for using int instead of long long 
