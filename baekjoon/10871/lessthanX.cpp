#include<iostream>
using namespace std;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	int num[10000];
	cin >> x >> n;
	for(int i=0; i<x; i++){
		cin>>num[i];
		if(num[i]<n) cout << num[i]<<'\n';;
	}
}
