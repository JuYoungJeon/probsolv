#include<iostream>

using namespace std;

struct node{
	node* lc=NULL, *rc=NULL;
};

node tree[50];

int dfs(node* n){
	if(n->lc==NULL&&n->rc==NULL) return 1;
	int ret =0;
	if(n->lc!=NULL) ret+= dfs(n->lc);
	if(n->rc!=NULL) ret+= dfs(n->rc);
	return ret;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	node* root;
	for(int i=0;i<N; i++){
		int p;
		cin >> p;
		if(p==-1){
			root=&tree[p];
			continue;
		}
		if(tree[p].lc==NULL) tree[p].lc=&tree[i];	
		else tree[p].rc = &tree[i];
	}

	int del;
	cin >> del;
	int ans=0;
	for(int i=0;i<N; i++){
		if(tree[i].lc==NULL&&tree[i].rc==NULL) {
			ans++;
			continue;
		}
		if((tree[i].lc==&tree[del]||tree[i].rc==&tree[del])&&(tree[i].lc==NULL||tree[i].rc==NULL)) ans++;
	}
	cout << ans - dfs(&tree[del]);
	
}
