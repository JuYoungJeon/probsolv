#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

pair<int, int> p[1000000];
vector<pair<int, int> > a;

int main(void){
	int N; 
	scanf("%d", &N);
	for(int i=0;i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		p[i]={x, y};
	}
	sort(p, p+N);
	
	a.push_back(p[0]);
	for(int i=1;i<N; i++){
		if(a.back().second>=p[i].first){
			a.back().second=max(a.back().second, p[i].second);
		}else{
			a.push_back(p[i]);
		}
	}
	int ans=0;
	for(auto& up: a){
		ans+=up.second-up.first;
	}
	printf("%d", ans);
}
