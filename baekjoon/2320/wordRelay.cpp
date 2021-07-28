#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<string>
using namespace std;
struct word{
	char s, e;
	int idx, len, visited;
};
map<char, int> lett;
vector<word> dict[5];
int maxvisit[16];
int search(char s){
	int ret=0;
	for (auto& w: dict[lett[s]]){
		int len=0;
		if(w.visited||maxvisit[w.idx]) continue;
		w.visited=1;
		len+=w.len;
		len+=search(w.e);
		w.visited=0;
		if(ret<len){
			ret=len;
			memset(maxvisit, 0, sizeof(maxvisit));
			for(int i=0;i<5; i++){
				for(auto& wo:dict[i]){
					if(wo.visited) maxvisit[wo.idx]=1;
				}
			}
		}
	}
	return ret;
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	lett.insert({'A',0});
	lett.insert({'E',1});
	lett.insert({'I',2});
	lett.insert({'O',3});
	lett.insert({'U',4});
	int N;
	cin >> N;
	for(int i =0; i<N; i++){
		string s;
		cin >> s;
		word newword={s[0],s.back(), i, (int)s.size(), 0};
		dict[lett[newword.s]].push_back(newword);
	}
	int ans=0;
	for(int i=0;i<5; i++){
		for(auto& w:dict[i]){
			int maxlen=0;
			w.visited=1;
			maxlen+=w.len;
			maxlen+=search(w.e);
			w.visited=0;
			if(ans<maxlen){
            	ans=maxlen;
            	memset(maxvisit, 0, sizeof(maxvisit));
            	for(int i=0;i<5; i++){
            	    for(auto& wo:dict[i]){
            	        if(wo.visited) maxvisit[wo.idx]=1;
            	    }
            	}
        	}
		}
	}
	cout << ans;
}
