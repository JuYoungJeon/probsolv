#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define pii pair<int, int>

vector<pair<pii, pii>> dates;
const pii s(3,1);
const pii e(11,30);

bool cmp(pair<pii, pii> a, pair<pii, pii> b){
	if(a.first==b.first)
		return a.second>b.second;
	else
		return a.first<b.first;
}

int dfs(int N, int idx){
	if(dates[idx].second>e) return 1;
	int minret=N+1;
	int nc=idx+1;
	bool isf=false;
	for(int i=idx+1; i<N; i++){
		auto d=dates[i];
		if(d.first<=dates[idx].second&&d.second>dates[idx].second){
			isf=true;
			if(dates[nc].second<dates[i].second) nc=i;
		}
	}
	if(isf) minret=min(minret, dfs(N, nc)+1);
	return minret;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	for(int i=0;i<N; i++){
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		dates.push_back({{sm,sd},{em,ed}});
	}
	sort(dates.begin(), dates.end(), cmp);
	int ans=N+1;
	int c=0;
	bool isf=false;
	for(int i=0;i<N; i++){
		auto d=dates[i];
		if(d.first<=s&&d.second>s){
			if(dates[i].second>s&&dates[c].second<dates[i].second) c=i;
			isf=true;
		}else if(d.first>e) break;
	}
	if(isf) ans=min(ans, dfs(N,c)); 
	if(ans==N+1) cout<< 0;
	else cout << ans;
}
