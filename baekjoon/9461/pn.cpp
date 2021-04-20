#include<iostream>

using namespace std;

long long p[101];

int main(void){
	int tc;
	cin >> tc;
	int prevN=6;
	p[1]=1, p[2]=1, p[3]=1;
	p[4]=2, p[5]=2;
	int smallest=1;
	int largest=5;
	for(int i=0; i<tc; i++){
		int n;
		cin >> n;
		for(; prevN<=n; prevN++){
			p[prevN]=p[smallest]+p[largest];
			smallest+=1;
			largest+=1;
		}
		
		cout << p[n]<<'\n';
	}
}
