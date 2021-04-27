#include <string>
#include <cctype>
#include <iostream>
using namespace std;
int main(void){
	string s;
	getline(cin, s);
	int cnt=0;
	bool end=false;
	for(int i=0; i<s.size(); i++){
		if(!end &&!isspace(s[i])){
			cnt+=1;
			end=true;
		}else if(isspace(s[i])) end=false;
	}
	cout <<cnt;
}
//Note: when reading line not word, use getline(cin, s)
