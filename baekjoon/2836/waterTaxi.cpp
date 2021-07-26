#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
vector<pii> rev;
int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0;i<N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a>b) rev.push_back({b, a});
	}
	int ans=M;
	sort(rev.begin(), rev.end());
	vector<pii> a;
	for(auto& p: rev){
		if(a.empty()) {a.push_back(p); continue;}
		if(p.first<=a.back().second){
			a.back().second=max(a.back().second, p.second);
		}else{
			a.push_back(p);
		}
	}
	for(auto &p:a){
		ans+=(p.second-p.first)*2;
	}
	printf("%d", ans);
}
