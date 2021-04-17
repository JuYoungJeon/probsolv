#include <iostream>

using namespace std;

int cache[1001];

int getNumTiles(int n){
	if (n==1 || n==2) return cache[n];
	if(cache[n]!=0) return cache[n];
	cache[n]= (getNumTiles(n-1)+getNumTiles(n-2)*2)%10007;
	return cache[n];
}


int main(void){
	int n;
	cin >> n;
	cache[1]=1;
	cache[2]=3;
	cout << getNumTiles(n);
}
