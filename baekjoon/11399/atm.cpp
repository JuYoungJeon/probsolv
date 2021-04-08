#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int p[1000]={0};

int greedy(int n){
	int sum=0;
	int acc=0;
	for(int i=0;i<n; i++){
		acc+=p[i];
		sum+=acc;
	}
	return sum;
}

int main(void){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin >> p[i];
	}
	sort(p, p+n);
	cout << greedy(n);
}
