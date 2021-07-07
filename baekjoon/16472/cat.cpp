#include<iostream>
#include<algorithm>
using namespace std;
int alph[26];
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	int l=0, r=0;
	int cnt=0;
	int ans=0;
	int currlen=0;
	while(l<=r&&r<s.size()){
		if(!alph[s[r]-'a'])cnt+=1;
		alph[s[r]-'a']+=1;
		r+=1;
		while(cnt>n){
			alph[s[l]-'a']-=1;
			if(!alph[s[l]-'a']) cnt-=1;
			l+=1;
			currlen-=1;
		}
		currlen+=1;
		ans=max(ans, currlen);
	}
	cout << ans;
}
