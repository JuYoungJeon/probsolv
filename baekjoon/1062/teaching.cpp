#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int used[26];
vector<string> words;

int getMaxCnt(int let, int cnt, int n, int k){
	if(cnt==k-5){
	    int ans=n;
    	for(int i=0; i<n; i++){
    	    for(int j=0; j<words[i].size(); j++){
    	        if(!used[words[i][j]-'a']){
    	            ans-=1;
    	            break;
    	        }
    	    }
    	}
		return ans;
	}
	int ret=0;
	for(int i=let; i<26; i++){
			if(i==0||i==13||i==19||i==8||i==2) continue;
			if(used[i]) continue;
			used[i]=1;
			ret=max(ret, getMaxCnt(i+1, cnt+1, n, k));
			used[i]=0;
	}
	return ret;
}

int main(void){
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		words.push_back(s);
	}
	used[0]=1, used[13]=1, used[19]=1;
	used[8]=1, used[2]=1;
	int ans = getMaxCnt(0, 0, n, k);
	cout << ans;
}
//특정 occurance이상 봐야되는게 아니라 다봐야함
