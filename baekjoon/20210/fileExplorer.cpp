#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cctype>

using namespace std;

vector<string> dissect(string a){
	vector<string> va;
	string tmp="";
	bool isString=false;
	for(char c: a){
		if(isString&&isdigit(c)){
			va.push_back(tmp);
			tmp="";
			isString=false;
		}else if(!isString&&!tmp.empty()&&isalpha(c)){
			va.push_back(tmp);
			tmp="";
			isString=true;
		}
		if(isalpha(c)) isString =true;
		else isString =false;
		tmp+=c;
	}
	va.push_back(tmp);
	return va;
}

bool cmp(string a, string b){
	vector<string> as, bs;
	as = dissect(a);
	bs = dissect(b);
	int N = min(as.size(), bs.size());
	bool ret =true;
	for(int i=0;i<N; i++){
		bool aisNum=isdigit(as[i][0]);
		bool bisNum=isdigit(bs[i][0]);
		//one is number and other is string
		if((aisNum&&!bisNum)||(!aisNum&&bisNum)){
			if (aisNum) return true;
			else return false;
		}
		//both are string
		if(!aisNum&&!bisNum){
			int ssize = min(as[i].size(), bs[i].size());
			for(int c=0;c<ssize;c++){
				if(as[i][c]==bs[i][c]) continue;
				if(tolower(as[i][c])==tolower(bs[i][c])) return as[i][c]<bs[i][c];
				else return tolower(as[i][c])<tolower(bs[i][c]);
			}
			if(as[i].size()!=bs[i].size()) return as[i].size()<bs[i].size();
		}
		//both are number
		if(aisNum&&bisNum){
			int aZero=0;
			int bZero=0;
			for(int j=0;j<as[i].size(); j++) {
				if(as[i][j]!='0') break;
				else aZero+=1;
			}
			for(int j=0;j<bs[i].size(); j++){
				if(bs[i][j]!='0') break;
				else bZero+=1;
			}
			as[i].erase(0, aZero);
			bs[i].erase(0, bZero);
			if(as[i].size()!=bs[i].size()) return as[i].size() < bs[i].size();
			for(int j=0;j<as[i].size(); j++){
				if(as[i][j]!=bs[i][j]) return as[i][j]<bs[i][j];
			}
			if(aZero!=bZero) return aZero < bZero;
		}
	}
	return as.size()<bs.size();
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<string> words;
	cin >> N;
	for(int i=0;i<N ;i++ ){
		string s;
		cin >> s;
		words.push_back(s);
	}
	sort(words.begin(), words.end(), cmp);
	for(string w: words){
		cout << w<<'\n';
	}
}
