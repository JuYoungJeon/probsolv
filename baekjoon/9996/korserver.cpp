#include<iostream>
#include<vector>
using namespace std;
vector<string> rgx;
string regex;
bool checkRegex(string t){
	int ri=1; 
	bool star=false;
	int ti=0;
	bool ans=true;
	for(int i=0; i<rgx[0].size(); i++){
		if(rgx[0][i]!=t[ti]){ ans=false; break;}
		else ti+=1;
	}
	while(ans&&ti<t.size()){
		if(ri==rgx.size()-1) break;
		if(rgx[ri][0]==t[ti]){
			bool match=true;
			for(int i=0; i<rgx[ri].size(); i++){
				if(rgx[ri][i]!=t[ti]){match=false; ti+=1;break;}
				else ti+=1;
			}
			if(match)ri+=1;
		}else ti+=1;
	}
	if(ri!=rgx.size()-1) ans=false;
	else{
		int nti=t.size()-1;
		for(int i=rgx[ri].size()-1; i>=0; i--){
			if(nti<ti||rgx[ri][i]!=t[nti]){ans=false; break;}
			else nti--;
		}
	}
	return ans;
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cin >> regex;
	string tmp="";
	for(int i=0; i<regex.size(); i++){
		if(regex[i]=='*'){
			rgx.push_back(tmp);
			tmp="";
		}else{
			tmp+=regex[i];
		}
	}
	rgx.push_back(tmp);
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		if(checkRegex(s)) cout << "DA\n";
		else cout <<"NE\n";
	}
}
