#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> d2s[1001];
int main(void){
	int n; 
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		int d, s;
		scanf("%d %d", &d, &s);
		d2s[d].push_back(s);
	}
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=1; i<1001; i++){
		for(auto &s: d2s[i]){
			if(pq.empty()||pq.top()<s||pq.size()<i){
				if(pq.size()==i) pq.pop();
				pq.push(s);
			}
		}
	}
	int ans=0;
	while(!pq.empty()){
		ans+=pq.top();
		pq.pop();
	}
	printf("%d", ans);
}
