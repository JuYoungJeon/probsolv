#include<iostream>
using namespace std;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	for(int i=1; i<=tc; i++){
		int a, b;
		cin >> a >> b;
		cout <<"Case #"<<i<<": "<<a+b<<'\n';
	}
}
