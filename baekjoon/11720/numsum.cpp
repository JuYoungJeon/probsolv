#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
	int n, sum=0;
	scanf("%d", &n);
	int t;
	for(int i=0; i<n; i++) {scanf("%1d", &t); sum+=t;}
	printf("%d", sum);
}
