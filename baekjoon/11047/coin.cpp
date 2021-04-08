#include <iostream>
#include <vector>

int coins[10];

using namespace std;

int greedy(int n, int k){
	int ans=0;
	int leftChange=k;
	for(int i=n-1; i>=0; i--){
		if(leftChange>=coins[i]){
			int numCoin = int(leftChange/coins[i]);
			leftChange-=(coins[i]*numCoin);
			ans+=numCoin;
		}
		if(leftChange==0) break;
	}
	return ans;
}

int main(){
	int n, k;
	cin >> n >> k;
	
	for(int i=0;i < n; i++){
		cin >> coins[i]; 	
	}
	cout << greedy(n, k);
}
