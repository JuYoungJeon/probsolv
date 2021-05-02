#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(void){
	int tc;
	cin >> tc;
	for(int i=0; i<tc; i++){
		int n;
		cin >> n;
		map<string, int> all;
		for(int j=0; j<n; j++){
			string t, type;
			cin >> t >> type;
			if(all.find(type)!=all.end()) all[type]+=1;
			else all[type]=1;
		}
		int ans=1;
		for(auto it=all.begin(); it!=all.end(); it++){
			ans*=(it->second+1);
		}
		cout << ans-1<<'\n';
	}
}
//모든 옷경우의 수를 구하기위해 (옷가지수 +1)*(옷가지수 *1)...-1하면됨
//+1을 하는 것은 안입는 경우까지 counting
//-1을 하는 것은 아무것도 안입은경우 빼주기
