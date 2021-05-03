#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(void){
	while(1){
		string s;
		getline(cin, s);
		if (s==".") break;
		int cntB=0;
		int cntS=0;
		bool bal=true;
		vector<char> last;
		for(int i=s.size()-1; i>=0; i--){
			if(s[i]==']'){cntB+=1;last.push_back(s[i]);}
			if(s[i]==')'){cntS+=1;last.push_back(s[i]);}
			if(s[i]=='('){
				if(cntS>0&&last.back()==')'){cntS--;last.pop_back();}
				else {bal=false; break;}
			}
			if(s[i]=='['){
				if(cntB>0&&last.back()==']'){cntB--;last.pop_back();}
				else{bal=false; break;}
			}
		}
		if(bal==false|| cntB!=0||cntS!=0){
			cout<< "no\n";
		}else cout << "yes\n";
	}
}
