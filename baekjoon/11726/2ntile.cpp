#include <iostream>

using namespace std;

int numTiles[1001];

int getTile(int n){
	if (n==1 || n==2) return numTiles[n];
	if (numTiles[n]!=0) return numTiles[n];
	numTiles[n]=getTile(n-1)+getTile(n-2);
	numTiles[n]%=10007;
	return numTiles[n];

}

int main(void){
	int n;
	cin >> n;
	numTiles[1]=1;
	numTiles[2]=2;
	cout << getTile(n);
}
