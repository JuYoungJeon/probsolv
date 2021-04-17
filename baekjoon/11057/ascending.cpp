#include <iostream>

using namespace std;

int cache[1001][10];

int getNumAscend(int n){
	for(int i=0; i<10; i++) cache[1][i]=1;
	for(int i=2; i<=n; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<=j;k++){
				cache[i][j]+=cache[i-1][k];
				cache[i][j]%=10007;
			}
		}
	}
	int ans=0;
	for(int i=0; i<10; i++){
		ans+=cache[n][i];
		ans%=10007;
	}
	return ans;
}
int main(void){
	int n; 
	cin >> n;
	cout << getNumAscend(n);
}
