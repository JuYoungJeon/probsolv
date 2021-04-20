#include <iostream>

using namespace std;

long long p[201][201];

int main(void){
	int n, k;
	cin >> n >> k;
	
	for(int i=1; i<=n; i++){
		p[i][1]=1;
		for(int j=2; j<=k; j++){
			for(int l=1; l<=i; l++){
				p[i][j]+=p[l][j-1]%1000000000;
			}
			p[i][j]+=1;
		}
	}
	cout << p[n][k]%1000000000;
			

}
