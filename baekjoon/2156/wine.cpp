#include <iostream>
#include <algorithm>

using namespace std;

long long cache[10001][3];
long long capacity[10001];

int main(void){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> capacity[i];

	cache[1][0]=0;
	cache[1][1]=capacity[1];
	cache[1][2]=capacity[1];
	for (int i=2; i<=n; i++){
		cache[i][0]=max(cache[i-1][0], cache[i-1][1]);
		cache[i][0]=max(cache[i][0], cache[i-1][2]);
		cache[i][1]=max(cache[i-1][0], cache[i-1][2])+capacity[i];
		cache[i][2]=cache[i-1][0]+capacity[i];
	}
	long long maxVal= max(cache[n][0], cache[n][1]);
	maxVal= max(maxVal, cache[n][2]);
	cout << maxVal;
}
