#include <cstdio>
using namespace std;

int main(void){
	int n;
	scanf("%d", &n);
	int i=2;
	while(n>1){
		if(n%i==0) {n/=i; printf("%d\n", i);}
		else i+=1;
	}
}
