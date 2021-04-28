#include <cstdio>
using namespace std;
int main(void){
	int a, b;
	scanf("%d\n%d", &a, &b);
	int minPrime=b;
	int sumPrime=0;
	for(int i=a; i<=b; i++){
		if(i==1) continue;
		bool isPrime =true;
		for(int j=2; j<i; j++){
			if(i%j==0) {isPrime=false; break;}
		}
		if(isPrime){
			sumPrime+=i;
			if(minPrime>i) minPrime=i;
		}
	}
	if(minPrime==1) minPrime=0;
	if(sumPrime==0)
		printf("-1");
	else
		printf("%d\n%d", sumPrime, minPrime);
	
}
//Note: read the instruction till the end! range의 각 end를 test해보기 (1 is not a prime number)	
