#include<iostream>
#include<string>
#include<deque>
#include<vector>
using namespace std;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	for(int i=0; i<tc; i++){
		string cmd;
		int nu;	deque<int> a;
		string t;
		cin >> cmd >> nu >> t;
		string tmp="";
		for(int j=0; j<t.size(); j++){
			if(t[j]=='[') continue;
			if((t[j]==']'||t[j]==',')&&tmp.size()!=0) {a.push_back(stoi(tmp));tmp="";}
			else tmp+=t[j];
		}
		int fob=0;
		vector<int> ans;
		bool err=false;
		for(int j=0; j<cmd.size(); j++){
			if(cmd[j]=='R') {fob+=1; fob%=2;}
			if(cmd[j]=='D'){
				if(a.empty()) {cout<<"error\n"; err=true; break;}
				if(fob==0){
					a.pop_front();
				}else{
					a.pop_back();
				}
			}
		}
		if(err) continue;
		cout << '[';
		while(!a.empty()){
			if(fob==0){
				cout<< a.front();
				a.pop_front();
			}else{
				cout<< a.back();
				a.pop_back();
			}
			if(!a.empty()) cout<< ',';
		}
		cout<<']'<<'\n';
	}
}
//Note: string 받는게 어려웠다... [a,b,c,d]로 되어있는 string 을 deque<int>로 받기..
