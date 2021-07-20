#include<string>
#include<iostream>
using namespace std;
int score[21];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	for(int i=0;i<=20; i++) score[i]=1;
	int sum=0;
	int cntFrame=0;
	int subCnt=0;
	int extraIdx;
	for(int i=0;i<s.size(); i++){
		if(s[i]=='-') subCnt+=1;
		else if(s[i]=='P'){
			int prev;
			if(s[i-1]=='-') prev=0;
			else prev=s[i-1]-'0';
			sum+=score[i]*(10-prev);
			score[i+1]+=1;
			subCnt+=1;
		}else if(s[i]=='S'){
			sum+=score[i]*10;
			score[i+1]+=1;
			score[i+2]+=1;
			subCnt+=2;
		}else{
			sum+=score[i]*(s[i]-'0');
			subCnt+=1;
		}
		if(subCnt%2==0) cntFrame+=1;
		if(cntFrame==10) {
			extraIdx=i+1;
			break;
		}
	}
	for(int i=extraIdx; i<s.size(); i++){
		if(s[i]=='-') continue;
		if(s[i]=='S') sum+=(score[i]-1)*10;
		else if(s[i]=='P'){
			int prev;
			if(s[i-1]=='-') prev=0;
			else prev=s[i-1]-'0';
			sum+=(score[i]-1)*(10-prev);
		}else sum+=(score[i]-1)*(s[i]-'0');
	}
	cout << sum;
}
