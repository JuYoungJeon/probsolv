#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main(void){
	int n;
	cin >>n;
	for(int tc=0; tc<n; tc++){
		string str;
		cin >> str;
		int target=-1;
		for(int i=str.size()-1; i>0; i--){
			if(str[i]>str[i-1]) {
				target=i-1;
				break;
			}
		}
		if(target==-1) {
			cout << str<<'\n';
			continue;
		}
		for(int i=str.size()-1; i>target; i--){
			if(str[i]>str[target]){
				swap(str[i], str[target]);
				break;
			}
		}
		sort(str.begin()+target+1, str.end());
		cout << str<<'\n';
	}
}
