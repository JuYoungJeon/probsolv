#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main (void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int ans=s.size();
	int acnt=0, bcnt=0;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='a') acnt+=1;
	}
	for(int i=0; i<s.size(); i++){
		bcnt=0;
		for(int j=i; j<i+acnt; j++){
			if(s[j%s.size()]=='b') bcnt+=1;
		}
		ans=min(bcnt, ans);
	}
	printf("%d", ans);
}
