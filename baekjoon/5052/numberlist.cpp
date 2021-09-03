#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string> nums;
		for(int i=0;i<n; i++){
			string s;
			cin >> s;
			nums.push_back(s);
		}
		sort(nums.begin(), nums.end());
		bool poss=true;
		for(int i=0;i<n-1; i++){
			if(nums[i]==nums[i+1].substr(0,nums[i].size())) { poss=false; break;}
		}
		if(poss) cout << "YES\n";
		else cout << "NO\n";
	}
}
