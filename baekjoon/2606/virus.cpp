#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int visited[101];
queue<int> q;
vector<vector<int> > connections(101, vector<int>());

int bfs(int ncom, int ncon){
	int v=0;
	visited[1]=1;
	q.push(1);
	while(!q.empty()){
		int f=q.front();
		q.pop();
		for(auto i=connections[f].begin(); i!=connections[f].end(); i++){
			if(visited[*i]) continue;
			visited[*i]=1;
			q.push(*i);
			v+=1;
		}
	}
	return v;
}
int main(void){
	int ncom;
	int ncon;

	scanf("%d", &ncom);
	scanf("%d", &ncon);
	for(int i=0;i <ncon; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		connections[a].push_back(b);
		connections[b].push_back(a);
	}
	int ans=bfs(ncom, ncon);
	printf("%d", ans);
}
