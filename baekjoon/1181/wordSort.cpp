#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
bool cmpWords(string a, string b){
	if(a.size()==b.size()) return a<b;
	return a.size()<b.size();
}
int main(void){
	int n;
	cin >> n;
	vector<string> words; 
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		words.push_back(s);
	}
	sort(words.begin(), words.end(), cmpWords);
	for(int i=0; i<n; i++){
		if (i==0|| words[i]!=words[i-1])cout<< words[i]<<'\n';;
	}
}
//Note: vector find 는 느리니깐 최대한 쓰지 않도록..!
