#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

int cap[53][53];
int RG[53][53];
vector<int> graph[53];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		getchar();
		char s, e; int c;
		scanf("%c %c %d", &s, &e, &c);
		s=(s<'a')? s-'A':s-'a'+26;
		e=(e<'a')? e-'A':e-'a'+26;
		graph[s].push_back(e);
		graph[e].push_back(s);
		cap[s][e]+=c;
		cap[e][s]+=c;
	}
	int s=0; int e=25;
	int ans=0;
	while(1){
		vector<int> par(53, -1);
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int cur=q.front();
			q.pop();
			for(auto& next:graph[cur]){
				if(cap[cur][next]-RG[cur][next]>0&&par[next]==-1){
					q.push(next);
					par[next]=cur;
					if(next==e)break;
				}
			}
		}
		if(par[e]==-1)break;
		int minFlow=1001;
		for(int i=e; i!=s;i=par[i]){
			minFlow=min(minFlow, cap[par[i]][i]-RG[par[i]][i]);
		}
		for(int i=e; i!=s; i=par[i]){
			RG[par[i]][i]+=minFlow;
			RG[i][par[i]]-=minFlow;
		}
		ans+=minFlow;
	}
	printf("%d", ans);
}
