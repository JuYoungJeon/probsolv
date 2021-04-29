#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int c[100];

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%d", c+i);
	vector<bool> comb(n);
	for(int i=1; i<=3; i++){
		comb[n-i]=1;
	}
	int maxSum=0;
	do{
		int sum=0;
		for(int i=0; i<n; i++){
			if(comb[i]){
				sum+=c[i];
			}
		}
		if(sum<=m) maxSum=max(sum, maxSum); 
	}while(next_permutation(comb.begin(), comb.end()));
	printf("%d", maxSum);
}
