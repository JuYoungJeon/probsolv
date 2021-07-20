#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int RG[401][401];
int cap[401][401];
vector<int> edges[401];

int main(void){
	int N, P;
	scanf("%d %d", &N, &P);
	for(int i=0;i<P; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
		cap[a][b]=1;
	}
	int s=1, e=2; 
	int ans=0;
	while(1){
		vector<int> parent(401, -1);
		queue<int> q;
		q.push(s);
		int minflow=10000;
		//BFS로 s->e까지 경로찾기 (parent에 경로 기록)
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(auto& nex: edges[cur]){
				if(cap[cur][nex]-RG[cur][nex]>0&&parent[nex]==-1){
					q.push(nex);
					parent[nex]=cur;
					if(e==nex) break;
				}
			}
		}
		//sink까지 경로를 못찾았다면 경로가 없음
		if(parent[e]==-1) break;
		//증가 경로로 새로 흘러줄 유량=경로중 최소 잔여 용량
		for(int i=e; i!=s; i=parent[i]){
			minflow=min(minflow, cap[parent[i]][i]-RG[parent[i]][i]);
		}
		//Flow graph 갱신
		for(int i=e; i!=s; i=parent[i]){
			RG[parent[i]][i]+=minflow;
			RG[i][parent[i]]-=minflow;
		}
		ans+=minflow;
	}
	printf("%d", ans);
}
