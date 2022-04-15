#include<iostream>
#include<vector>
using namespace std;

vector<int> ryanIdx;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	for(int i=0; i<N; i++){
		int t;
		cin >> t;
		if (t==1) ryanIdx.push_back(i);
	}
	int s =0;
	int e = K-1;
	int ans = N+1;
	while(e<ryanIdx.size()){
		ans = min(ans, ryanIdx[e]-ryanIdx[s]+1);
		s++;
		e++;
	}
	if(ans==N+1) cout << -1;
	else cout << ans;
}
