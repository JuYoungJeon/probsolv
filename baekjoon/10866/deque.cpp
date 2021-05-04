#include<iostream>
#include<deque>
using namespace std;
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ncmd;
	cin >> ncmd;
	deque<int> dq;
	for(int i=0; i<ncmd; i++){
		string s;
		cin >> s;
		if(s=="push_back"){
			int n;
			cin >> n;
			dq.push_back(n);
		}
		if(s=="push_front"){
			int n;
			cin >> n;
			dq.push_front(n);
		}
		if(s=="pop_front"){
			if(dq.empty()) cout<<"-1\n";
			else {cout<< dq.front()<<'\n'; dq.pop_front();}
		}
		if(s=="pop_back"){
			if(dq.empty()) cout << "-1\n";
			else {cout<<dq.back()<<'\n'; dq.pop_back();}
		}
		if(s=="size"){
			cout<< dq.size()<<'\n';
		}
		if(s=="empty"){
			cout << dq.empty()<<'\n';
		}
		if(s=="front"){
			if(dq.empty()) cout<<"-1\n";
			else cout << dq.front()<<'\n';
		}
		if(s=="back"){
			if(dq.empty()) cout<< "-1\n";
			else cout<< dq.back() <<'\n';
		}
	}
}
