#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

vector<ll> tree;
ll elem[100000];

ll initTree(int idx, int s, int e){
	if(s==e) return tree[idx]=elem[s];
	int mid = (s+e)/2;
	return tree[idx]=initTree(idx*2, s, mid)+initTree(idx*2+1, mid+1, e);
}
ll getSum(int idx, int s, int e, int l, int r){
	if(s>r||e<l) return 0;
	if(l<=s&&e<=r) return tree[idx];
	int mid=(s+e)/2;
	return getSum(idx*2, s, mid, l, r)+getSum(idx*2+1, mid+1, e, l, r);
}

void modTree(int idx, int s, int e, int i, int diff){
	if(s>i||e<i) return;
	tree[idx]+=diff;
	if(s!=e){
		int mid = (s+e)/2;
		modTree(idx*2, s, mid, i, diff);
		modTree(idx*2+1, mid+1, e, i, diff);
	}
}

int main(void){
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i=0;i<n; i++){
		scanf("%lld", &elem[i]);
	}
	tree.resize(4*n);
	initTree(1, 0, n-1);
	for(int i=0;i<q;i++){
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if(x>y) swap(x, y);
		ll ans=getSum(1, 0, n-1, x-1, y-1);
		ll diff = b-elem[a-1];
		elem[a-1]=b;
		modTree(1, 0, n-1, a-1, diff);
		printf("%lld\n", ans);
	}
}
