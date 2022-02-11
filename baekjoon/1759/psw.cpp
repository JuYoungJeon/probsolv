#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

char v[5]={'a','e','i','o','u'};
int L, C;
vector<char> ch;

void psw(string word,int idx, int cnt, int nv, int nc){
	if(cnt==L){
		if(nv>=1&&nc>=2) cout << word<<'\n';
		return;
	}
	if(cnt<L&&idx==C) return;
	for(int i=idx; i<C; i++){
		bool isVowel=false;
		for(int j=0; j<5; j++){
			if(ch[i]==v[j]){
				isVowel=true;
				break;
			}
		}
		if(isVowel) psw(word+ch[i], i+1, cnt+1, nv+1, nc);
		else psw(word+ch[i], i+1, cnt+1, nv, nc+1);
	}
	
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> C;
	for(int i=0;i<C; i++){
		char c;
		cin >> c;
		ch.push_back(c);
	}
	sort(ch.begin(), ch.end());
	psw("", 0, 0, 0, 0);
}
