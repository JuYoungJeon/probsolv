#include <iostream>
#include <algorithm>

using namespace std;

int longest[1001][2];

int main(void){
	int n;
	cin >> n;
	int number[1001];
	for(int i=1; i<=n; i++)
		cin >> number[i];

	longest[1][0]=0;
	longest[1][1]=1;
	for(int i=2; i<=n; i++){
		longest[i][0]=max(longest[i-1][0],longest[i-1][1]);

		int prevLongest=0;
		for(int j=i-1;j>0; j--){
			if(number[j]<number[i]) prevLongest=max(prevLongest, longest[j][1]);
		}
		longest[i][1]=prevLongest+1;
		//cout << i<< longest[i][0] <<' '<<longest[i][1]<<'\n';
	}
	cout << max(longest[n][0], longest[n][1]);
}

		
