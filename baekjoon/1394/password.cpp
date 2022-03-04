#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string letters, pwd;
	map<char, int> l2idx;
	long long cache[1000001];

	cin >> letters;
	cin >> pwd;
	cache[0]=1;

	int ans =0; 
	for(int i =0;i<letters.size(); i++){
		l2idx.insert({letters[i], i+1});
	}
	for(int i=0;i<pwd.size(); i++){
		int unit=1;
		cache[i+1]=cache[i]*letters.size();
		cache[i+1]%=900528;
		ans+=(cache[i]*l2idx.find(pwd[pwd.size()-i-1])->second)%900528;
	}
	cout << ans%900528;
}
