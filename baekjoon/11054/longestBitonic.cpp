#include <iostream>
#include <algorithm>

using namespace std;

int longest[1001];
int longestRev[1001];
int number[1001];

int main(void){

	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> number[i];
	
	longest[1]=1;
	longestRev[n]=1;
	for (int i=2; i<=n; i++){
		int prevMax=0;
		for(int j=i-1; j>0; j--){
			if(number[j]<number[i]) prevMax=max(prevMax, longest[j]);
		}
		longest[i]=prevMax+1;
	}
	for(int i=n-1; i>0; i--){
		int prevMax=0;
		for(int j=i+1; j<=n; j++){
			if(number[j]<number[i]) prevMax=max(prevMax, longestRev[j]);
		}
		longestRev[i]=prevMax+1;

	}
	int ans=0; 
	for(int i=1; i<=n; i++){
		ans=max(ans, longest[i]+longestRev[i]-1);
	}
	cout << ans;
}

