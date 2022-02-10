#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int cnt[26][8];
int match[26];
vector<pair<int, int>>score;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cnt, 0, sizeof(cnt));
	memset(match, 0, sizeof(match));

	int N;
	cin >> N;
	vector<string> words;
	for(int i=0;i<N; i++){
		string t;
		cin >> t;
		words.push_back(t);
	}
	for(int i=0;i<N; i++){
		for(int j=0;j<words[i].size(); j++){
			cnt[words[i][j]-'A'][words[i].size()-j-1]+=1;
		}
	}
	for(int i=0;i<26; i++){
		int sc=0;
		for(int j=0;j<8; j++){
			sc+=cnt[i][j]*pow(10,j+1);
		}
		score.push_back({sc, i});
	}
	sort(score.begin(), score.end(), greater<>());
	int val=9;
	for(int i=0;i<score.size(); i++){
		if(score[i].first==0) break;
		match[score[i].second]=val;
		val--;
	}
	int ans=0;
	for(int i=0;i<N; i++){
		int digits=1;
		int num=0;
		for(int j=words[i].size()-1; j>=0; j--){
			num+=(match[words[i][j]-'A']*digits);
			digits*=10;
		}
		ans+=num;
	}
	cout << ans;
}
