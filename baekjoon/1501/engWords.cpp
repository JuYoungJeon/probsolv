#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int dl[10001][52];
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<string> dict;
	for(int i=0; i<N; i++){
		string s;
		cin >> s;
		dict.push_back(s);
		for(int j=1; j<s.size()-1; j++){
			if(s[j]>='a') dl[i][s[j]-'a'+26]+=1;
			else dl[i][s[j]-'A']+=1;
		}
	}
	int M;
	cin >> M;
	cin.ignore();
	vector<int> ans;
	for(int i=0; i<M; i++){
		string s;
		getline(cin, s);
		string t="";
		int an=0;
		for(int j=0; j<=s.size(); j++){
			if(s[j]==' '||j==s.size()) {
				if(t.empty()) continue;
				int tl[52];
				memset(tl, 0, sizeof(tl));
				for(int k=1; k<t.size()-1; k++){
					if(t[k]>='a') tl[t[k]-'a'+26]+=1;
					else tl[t[k]-'A']+=1;
				}
				int a=0; 
				for(int k=0; k<N; k++){
					if(dict[k].size()!=t.size()) continue;
					if(dict[k][0]!=t[0]||dict[k].back()!=t.back()) continue;
					bool fail =false;
					for(int l=0; l<52; l++){
						if(dl[k][l]!=tl[l]){fail=true; break;}
					}
					if(fail) continue;
					a+=1;
				}
				t="";
				if(!a) continue;
				if(an) an*=a;
				else an=a;
			}else t+=s[j];
		}
		ans.push_back(an);
	}
	for(int i=0; i<M; i++) cout << ans[i] <<'\n';
}
