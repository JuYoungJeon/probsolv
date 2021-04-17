#include <iostream>

using namespace std;

int cache[1001];
int p[1001];

int getMaxPrice(int n){
	for(int i=1; i<=n;i++){
		for(int j=1; j<=i; j++){
			cache[i]=max(cache[i], cache[i-j]+p[j]);
		}
	}
	return cache[n];
}

int main(void){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> p[i] ;
	}
	cout << getMaxPrice(n);
}
