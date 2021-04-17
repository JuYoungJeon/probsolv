#include <iostream>
#include <vector>

using namespace std;

int cache[11];

int main(void){
	int tc;
	cin >> tc;
	cache[1]=1;
	cache[2]=2;
	cache[3]=4;
	vector<int> ans; 
	for(int j=4; j< 11; j++){
		cache[j]=cache[j-1]+cache[j-2]+cache[j-3];
	}
	for(int i=0; i<tc; i++){
		int n;
		cin >> n;
		ans.push_back(cache[n]);
	}
	for(int i=0; i<tc; i++)
		cout << ans[i] <<'\n';
}
