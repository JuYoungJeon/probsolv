#include<cstdio>
#include<vector>
#define ll long long 
#define MAX_MUL 1000000007
using namespace std;
vector<ll> tree;
vector<ll> arr;
ll initSegTree(int node, int start, int end){
	if(start==end) return tree[node]=arr[start];
	int mid = (start+end)/2;
	tree[node]=initSegTree(node*2, start, mid)*initSegTree(node*2+1, mid+1, end)%MAX_MUL;
	return tree[node];
}

void modSegTree(int node, int start, int end, int idx, int diff){
	if(!(start<=idx&&end>=idx)) return;
	if (start==end) {tree[node]=diff; return;}
	int mid = (start+end)/2;
	modSegTree(node*2, start, mid, idx, diff);
	modSegTree(node*2+1, mid+1, end, idx, diff);
	tree[node]=tree[node*2]*tree[node*2+1] % MAX_MUL;
}

ll getMult(int node, int start, int end, int left, int right){
	if(start>right|| end<left) return 1;
	if(left<=start && end<=right) return tree[node];
	int mid = (start+end)/2;
	return getMult(node*2, start, mid, left, right)*getMult(node*2+1, mid+1, end, left, right)%MAX_MUL;
}

int main(void){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	arr.resize(n);
	tree.resize(n*4);
	for(int i=0; i<n; i++){
		scanf("%lld", &arr[i]);
	}
	initSegTree(1, 0, n-1);
	for(int i=0; i<m+k; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a==1){
			modSegTree(1, 0, n-1, b-1, c);
		}else if(a==2){
			printf("%lld\n", getMult(1, 0, n-1, b-1, c-1));
		}
	}

}
//Modify할때 먼저 이후의 것들을 부르고 그것을 곱함
// diff 사용이아님:
