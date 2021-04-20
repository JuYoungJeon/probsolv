#include <iostream>
#include <algorithm>
using namespace std;

int d[30];

int main(void){
	int n;
	cin >> n;
	d[0]=1;
	d[2]=3;
	for(int i=3; i<=n; i++){
		if(i%2!=0) {
			d[i]=0;
			continue;
		}
		d[i]+=d[i-2]*d[2];
		for(int j=2; j<=i/2; j++)
			d[i]+=d[i-j*2]*2;
	}
	cout << d[n];
}
