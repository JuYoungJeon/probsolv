#include<cstdio>
#include<vector>
#include<algorithm>

#define MAX_VAL 1000000001
using namespace std;
int arr[100001];
vector<pair<int, int> > tree;

pair<int, int> initSegTree(int node, int start, int end){
	if(start==end) return tree[node]=make_pair(arr[start], arr[start]);
	int mid = (start+end)/2;
	pair<int, int> front = initSegTree(node*2, start, mid);
	pair<int, int> rear = initSegTree(node*2+1, mid+1, end);
	return tree[node]=make_pair(min(front.first, rear.first), max(front.second, rear.second));
}

pair<int, int> getMaxMin(int node, int start, int end, int left, int right){
	if(right<start||left>end) return make_pair(MAX_VAL, 0);
	if(start>=left&& end <=right) return tree[node];
	int mid= (start+end)/2;
	pair<int, int> front = getMaxMin(node*2, start, mid, left, right);
	pair<int, int> rear = getMaxMin(node*2+1, mid+1, end, left, right);
	return make_pair(min(front.first, rear.first), max(front.second, rear.second));
}

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	tree.resize(n*4);
	initSegTree(1, 0, n-1);
	for(int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		pair<int, int> ans= getMaxMin(1, 0, n-1, a-1, b-1);
		printf("%d %d\n", ans.first, ans.second);
	}
}
