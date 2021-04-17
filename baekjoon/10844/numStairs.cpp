#include <iostream>

using namespace std;

int cache[101][10];

long long getPerm(int n){
	for(int i=1; i<10; i++) cache[1][i]=1;
	for(int i=2; i<=n; i++){
		for(int j=0; j<=9; j++){
			if(j==0) cache[i][j]=cache[i-1][j+1];
			else if(j==9) cache[i][j]=cache[i-1][j-1];
			else cache[i][j]=cache[i-1][j-1]+cache[i-1][j+1];
			cache[i][j]%=1000000000;
		}
	}
	long long ans=0;
	for(int i=0;i<10; i++) ans+=cache[n][i];
	ans%=1000000000;
	return ans;
}

int main(void){
	int n;
	cin >> n;
	cout << getPerm(n);

}
