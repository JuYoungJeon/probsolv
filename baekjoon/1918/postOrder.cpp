#include<iostream>
#include<string>
#include<stack>

using namespace std;
stack<char> st;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	string ans="";
	for(auto& c: s){
		if(c>='A'&&c<='Z') {
			ans+=c;
		}else{
			if(!st.empty()){
				char t = st.top();
				if((c=='+'||c=='-')&&t!='('){
					while(!st.empty()&&t!='('){
						ans+=t;
						st.pop();
						if(!st.empty())t=st.top();
					}
				}else if(c=='*'||c=='/'){
					if(t=='*'||t=='/') {ans+=t; st.pop();}
				}else if(c==')'){
					while(!st.empty()&&t!='('){
						ans+=t;
						st.pop();
						if(!st.empty())t=st.top();
					}
					st.pop();
				}
			}
			if(c!=')')st.push(c);
		}
	}
	while(!st.empty()) { ans+=st.top(); st.pop(); }
	cout << ans;

}
