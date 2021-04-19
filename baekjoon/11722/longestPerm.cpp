#include <iostream>
#include <algorithm>

using namespace std;

int longest[1001];
int number[1001];

int main(void){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> number[i];
	
	longest[1]=1;
	for (int i=2; i<=n; i++){
		int prevLongest=0;
		for(int j=i-1; j>0 ;j--)
			if(number[j] > number[i]) prevLongest=max(prevLongest, longest[j]);

		longest[i]=prevLongest+1;
	}
	int ans =0;
	for(int i=1; i<=n; i++)
		ans=max(ans, longest[i]);
	cout << ans;
}
