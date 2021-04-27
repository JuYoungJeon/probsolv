#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int alphaVisit[26];

int main(void){
	int words;
	cin >> words;
	int ans=0;
	for(int i=0; i<words; i++){
		memset(alphaVisit, 0, sizeof(alphaVisit));
		string word;
		cin >> word;
		bool isgw=true;
		for(int j=0; j<word.size(); ){
			if(alphaVisit[word[j]-'a']) {isgw=false; break;}
			alphaVisit[word[j]-'a']=1;
			char currAlpha=word[j];
			while(word[j]==currAlpha) j+=1;
		}
		if(isgw) ans+=1;
	}
	cout << ans;
}


