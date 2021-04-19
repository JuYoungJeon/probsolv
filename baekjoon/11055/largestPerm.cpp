#include <iostream>
#include <algorithm>

using namespace std;

int maxSum[1001];

int main(void){
	int n;
	cin >> n;
	int num[1001];
	for(int i=1; i<=n;i++){
		cin >> num[i];
	}
	maxSum[1]=num[1];
	for(int i=2; i<=n; i++){
		int prevMax=0;
		for(int j=i-1; j>0; j--){
			if(num[i]>num[j]) prevMax=max(prevMax, maxSum[j]);
		}
		maxSum[i]=prevMax+num[i];
	}
	int ans =0;
	for(int i=1; i<=n; i++)
		ans=max(ans, maxSum[i]);
	cout << ans;
		
}
