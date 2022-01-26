#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

#define MAXIDX 100000
int innode[MAXIDX];
int visited[MAXIDX];
vector<int> tree[MAXIDX];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc=1;
	while(1){
		bool endFlag=false;
		int maxIdx=0;
		memset(innode, 0, sizeof(innode));
		memset(visited, 0, sizeof(visited));
		while(1){
			int u, v;
			cin >> u >> v;
			if(u==-1&&v==-1){
				endFlag = true;
				break;
			}
			if(u==0&&v==0){
				break;
			}
			tree[u].push_back(v);
			innode[v]+=1;
			visited[u]=1;
			visited[v]=1;
			maxIdx=max(u, maxIdx);
			maxIdx=max(v, maxIdx);
		}
		if(endFlag) break;
		bool isTree=true;
		int rootIdx=-1;
		for(int i=1;i<=maxIdx; i++){
			if(visited[i]&&!innode[i]) {
				rootIdx=i;
				visited[i]=0;
			}
			if(innode[i]>1){
				isTree=false;
			}
		}
		if(maxIdx!=0&&(rootIdx==-1||!isTree)) {
			cout << "Case "<<tc++<<" is not a tree.\n";
			for(int i=1;i<=maxIdx; i++) tree[i].clear();
			continue;
		}
		queue<int> q;
		q.push(rootIdx);
		while(!q.empty()){
			int c = q.front();
			q.pop();
			for(int n:tree[c]){
				visited[n]=0;
				q.push(n);
			}
		}
		for(int i=1;i<=maxIdx; i++){
			if(visited[i]==1) {
				isTree=false;
			}
		}
		if(!isTree) cout << "Case "<<tc++<<" is not a tree.\n";
		else cout <<"Case "<<tc++<<" is a tree.\n";
		for(int i=1;i<=maxIdx; i++) tree[i].clear();
	}
}
