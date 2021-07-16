#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(1){
		string s;
		getline(cin, s);
		if(s=="#") break;
		vector<string> ps;
		string param="";
		bool sword=false;
		bool eword=false;
		bool ans=true;
		for(int i=0;i<s.size(); i++){
			if(s[i]=='>') {
				if(eword){
					if(ps.empty()||param.size()>ps.back().size()||ps.back().substr(0,param.size())!=param){
						ans=false;
						break;
					}
					ps.pop_back();
					eword=false;
				}else{
					if(param.back()!='/') ps.push_back(param);
					sword=false;
				}
				param="";
				continue;
			}
			if(sword||eword) param+=s[i];
			if(s[i]=='<'&&s[i+1]=='/'){ eword=true;i++;}
			else if(s[i]=='<') sword=true;

		}
		if(ps.size()>0) ans=false;
		if(ans) cout << "legal\n";
		else cout <<"illegal\n";

	}
}
