#include<iostream>
#include<vector>
using namespace std;
string s;
int prevP=0;
bool checkPPAP(int a, int b){
	bool ret=true;
	int cnt;
	if(prevP>2) cnt=2; 
	else cnt = prevP;
	prevP=prevP-cnt;
	for(int i=a; i<b; i++){
		if(s[i]=='P') {if(cnt==2) prevP+=1;if(cnt<2) cnt+=1; if(cnt==3) cnt+=1;}
		if(s[i]=='A') {if(cnt==2)cnt+=1;else return false;}
		if(cnt==4){
			cnt=0;
			ret=checkPPAP(i,s.size());
			break;
		}
	}
	if(prevP>1||cnt>1) return false;
	return ret;
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	if(checkPPAP(0, s.size())) cout << "PPAP";
	else cout << "NP";
}
