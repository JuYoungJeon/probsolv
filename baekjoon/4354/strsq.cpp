#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> kmp(string s){
	int ss=s.size();
	vector<int> pi(ss, 0);
	int j=0;
	for(int i=1; i<ss; i++){
		while(j>0&&s[j]!=s[i]){
			j=pi[j-1];
		}
		if(s[i]==s[j]) {
			pi[i]=j+1;
			j+=1;
		}else{
			pi[i]=0;
		}
	}
	return pi;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(1){
		string s;
		cin >> s;
		if(s==".") break;
		vector<int> a = kmp(s);
		int idx=a[a.size()-1];
		int ans=1;
		int diff=a.size()-a[a.size()-1];
		while(idx>diff){
			idx=a[idx-1];
			ans+=1;
		}
		if(idx!=0) ans+=1;
		if(idx<diff) ans=1;

		cout<<ans<<'\n';
	}
}
