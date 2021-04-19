#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int sum[100001];
int number[100001];

int main(void){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &(number[i]));
	
	int maxVal=-1000;
	for(int i=1; i<=n; i++){
		sum[i]=max(number[i], sum[i-1]+number[i]);
		maxVal=max(maxVal, sum[i]);
	}
	printf("%d", maxVal);
}

