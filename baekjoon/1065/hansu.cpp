#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int s;
	cin >> s;
	int ans=0;
	for(int i=1; i<=s; i++){
		string t=to_string(i);
		bool isAns=true;
		for(int j=1; j<t.size(); j++){
			if(t.size()==1) break;
			if((t[j]-'0')-(t[j-1]-'0')!=(t[1]-'0')-(t[0]-'0')) {
				isAns=false;
				break;
			}
		}
		if (isAns) ans+=1;
	}
	cout<< ans;
}
