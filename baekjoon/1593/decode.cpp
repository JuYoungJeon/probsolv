#include<iostream>
#include<string>

using namespace std;

int alph[52];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int g, ns;
	cin >> g >> ns;
	string W, S;
	cin >> W;
	cin >> S;
	int cnt=0;
	for(int i=0;i<g; i++){
		if(W[i]>96) alph[26+W[i]-'a']+=1;
		else alph[W[i]-'A']+=1;
		cnt+=1;
	}
	int ans=0;
	for(int i=0;i<g; i++){
		int next =S[i]>96? 26+S[i]-'a': S[i]-'A';
		if(alph[next]>0) cnt-=1;
		alph[next]-=1;
	}
	if(cnt==0) ans+=1;
	int s=0, e=g;
	while(e<ns){
		int prev = S[s]>96? 26+S[s]-'a':S[s]-'A';
		int next = S[e]>96? 26+S[e]-'a':S[e]-'A';
		if(alph[prev]>=0) cnt+=1;
		alph[prev]+=1;
		if(alph[next]>0) cnt-=1;
		alph[next]-=1;
		if(cnt==0) ans+=1; 
		s+=1, e+=1;
	}
	cout << ans;
}
