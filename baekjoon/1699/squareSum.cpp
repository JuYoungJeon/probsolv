#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std; 

int minSum[100001];

int main(void){
	int n;
	scanf("%d", &n);

	minSum[1]=1;
	int maxSquare=2;
	for(int i=2; i<=n; i++){
		if(maxSquare*maxSquare==i) {
			minSum[i]=1;
			maxSquare++;
		}else{
			int prevSq = maxSquare-1;
			minSum[i]=100000;
			while(prevSq >= 1){
				minSum[i]=min(minSum[i], minSum[prevSq*prevSq]+minSum[i-prevSq*prevSq]);
				prevSq--;
			}
		}
	}
	cout << minSum[n];
}
