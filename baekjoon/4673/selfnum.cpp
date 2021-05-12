#include <cstdio>
#include <vector>
using namespace std;
vector<bool> numbers(10001, true);
void d(int n){
	if(n>10000) return;
	if(numbers[n]) {
		printf("%d\n", n);
	}
	int t=n;int sum=n;
	sum+=t/10000; t%=10000;
	sum+=t/1000; t%=1000;
	sum+=t/100; t%=100;
	sum+=t/10; t%=10;
	sum+=t;
	if(sum<=10000) numbers[sum]=false;
	
}
int main(void){
	for(int i=1; i<=10000; i++){
		d(i);
	}

}
