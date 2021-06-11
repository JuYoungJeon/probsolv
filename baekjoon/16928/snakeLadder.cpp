#include<cstdio>
#include<algorithm>
#include<queue>
#include<climits>
#define INF 100 
using namespace std;
int dp[101];
int map[101];	//0:nothing 1:ladder_start 2:snake_start
int ladderOrSnake[101];
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		map[x]=1;
		ladderOrSnake[x]=y;
	}
	for(int i=0; i<m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		map[u]=2;
		ladderOrSnake[u]=v;
	}
	for(int i=2; i<101; i++) dp[i]=INF;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int next = q.front();
		q.pop();
		if(map[next]!=0){
			if(dp[ladderOrSnake[next]]>dp[next]){
				dp[ladderOrSnake[next]]=dp[next];
				q.push(ladderOrSnake[next]);
			}
			continue;
		}
		for(int i=1; i<7; i++){
			if(next+i<101&&dp[next]+1<dp[next+i]){
				dp[next+i]=dp[next]+1;
				q.push(next+i);
			}
		}
	}
	printf("%d", dp[100]);
}
//BFS로 폴기
