#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
int main(void){
	int tc;
	scanf("%d", &tc);
	for(int i=0; i<tc; i++){
		int conn[501][501]={0};
		int innode[501]={0};
		int rank[501]={0};
		int rt[501]={0};
		int n;
		scanf("%d", &n);
		for(int j=1; j<=n; j++){
			int team;
			scanf("%d", &team);
			rank[team]=j;
			rt[j]=team;
		}
		for(int j=1; j<=n; j++){
			for(int k=j+1; k<=n; k++){
				conn[rt[j]][rt[k]]=1;
				innode[rt[k]]+=1;
			}
		}
		int m;
		scanf("%d", &m);
		for(int j=0; j<m; j++){
			int a, b;
			scanf("%d %d", &a, &b);
			if(rank[a]>rank[b]) swap(a, b);
			conn[a][b]=0;
			innode[b]-=1;
			conn[b][a]=1;
			innode[a]+=1;
		}
		vector<vector<int> > edge(n+1, vector<int>());
		queue<int> q;
		for(int j=1; j<=n; j++){
			if(!innode[j]) q.push(j);
			for(int k=1; k<=n ;k++){ 
				if(conn[j][k]) edge[j].push_back(k);
			}
		}
		vector<int> ans;
		bool inf=false;
		while(!q.empty()){
			int nn=q.front();
			ans.push_back(nn);
			q.pop();
			int numZ=0;
			for(auto & e: edge[nn]){
				innode[e]-=1;
				if(!innode[e]){numZ+=1; q.push(e);}
				if(numZ>1) {inf=true; break;}
			}
		}
		if(inf) printf("?\n");
		else if(ans.size()!=n) printf("IMPOSSIBLE\n");
		else {
			for(auto & nn:ans) printf("%d ", nn);
			printf("\n");
		}
	}
}
//NOTE: 처음에 모든 순서를 설정해놓아야함
