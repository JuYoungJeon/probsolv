#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int dp[501];
int w[501];
int innode[501];
vector<int> edge[501];
int main(void){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n; i++){
		scanf("%d", &w[i]);
		int t;
		do {
			scanf("%d", &t);
			if(t!=-1) {
				edge[t-1].push_back(i);
				innode[i]+=1;
			}
		}while(t!=-1);
	}
	queue<int> next;
	for(int i=0; i<n; i++){
		if(innode[i]==0) next.push(i);
	}
	while(!next.empty()){
		int t= next.front();
		next.pop();
		dp[t]+=w[t];
		for(auto &e: edge[t]){
			dp[e]=max(dp[e], dp[t]);
			innode[e]-=1;
			if(innode[e]==0) next.push(e);
		}
	}
	for(int i=0;i<n; i++){
		printf("%d\n", dp[i]);
	}
}
