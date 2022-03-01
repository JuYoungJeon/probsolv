#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int tree[1001][2];

int order[1001][2];
int ordIdx[1001][2];
int visited[1001];

void getTree(int node, int N){
	if(ordIdx[node][0]==N-1) return;
	if(node==0) return;
	int lidx = order[ordIdx[node][0]+1][0];
	if(!visited[lidx]&&ordIdx[lidx][1]<ordIdx[node][1])
		tree[node][0]=order[ordIdx[node][0]+1][0];
	for(int i=ordIdx[node][0]+1; i<N; i++){
		if(visited[order[i][0]]) break;
		if(ordIdx[order[i][0]][1]>ordIdx[node][1]){
			tree[node][1]=order[i][0];
			break;
		}
	}
	visited[tree[node][0]]=1;
	visited[tree[node][1]]=1;
	getTree(tree[node][0], N);
	getTree(tree[node][1], N);
}

void postOrder(int node){
	if(node==0) return;
	postOrder(tree[node][0]);
	postOrder(tree[node][1]);
	cout << node<<' ';
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int TC;
	cin >> TC;
	while(TC--){
		memset(tree, 0, sizeof(tree));
		memset(visited, 0, sizeof(visited));
		memset(order, 0, sizeof(order));
		memset(ordIdx, 0, sizeof(ordIdx));
		int N;
		cin >> N;
		for(int i=0;i<N; i++){
			cin >> order[i][0];
			ordIdx[order[i][0]][0]=i;
		}
		for(int i=0;i<N; i++){
			cin >> order[i][1];
			ordIdx[order[i][1]][1]=i;
		}
		int root = order[0][0]; 
		visited[root]=1;
		getTree(root, N);
		postOrder(root);
		cout <<'\n';
	}
}
