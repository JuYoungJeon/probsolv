#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> edges[1001];
int innode[1001];

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		int ns;
		scanf("%d", &ns);
		int s, ps;
		for(int j=0; j<ns; j++){
			scanf("%d", &s);
			if(j==0) { ps=s;}
			else{ edges[ps].push_back(s); innode[s]+=1; ps=s;}
		}
	}
	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(innode[i]==0) q.push(i);
	}
	vector<int> ans;
	while(!q.empty()){
		int curr=q.front();
		q.pop();
		ans.push_back(curr);
		for(auto&s: edges[curr]){
			innode[s]-=1;
			if(innode[s]==0) q.push(s);
		}
	}
	if(ans.size()!=n) printf("0");
	else{
		for(auto& a: ans) printf("%d\n", a);
	}
}
