#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define pii pair<int, int>
pii arr[500000];
vector<int> tree(500000*4);

int getMax(int node, int s, int e, int l, int r){
	if(s>r||e<l) return 0;
	if(l<=s&&e<=r) return tree[node];
	int mid = (s+e)/2;
	return getMax(node*2, s, mid, l, r)+getMax(node*2+1, mid+1, e, l, r);
}
void update(int node, int s, int e, int idx){
	if(s>idx || e<idx) return ;
	tree[node]+=1;
	if(s!=e){
		int mid=(s+e)/2;
		update(node*2, s,mid, idx);
		update(node*2+1, mid+1,e, idx);
	}
}

int main(void){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n; i++){
		pii t;
		scanf("%d", &t.first);
		t.second=i;
		arr[i]=t;
	}
	sort(arr, arr+n, [&](pii &a, pii&b){ return a.first< b.first;});
	for(int i=0;i<n; i++) arr[i].first=i;
	sort(arr, arr+n, [&](pii &a, pii &b){ return a.second<b.second;});
	int ans[500000]; 
	for(int i=0;i<n; i++){
		int a = getMax(1, 0,n-1,0, arr[i].first);
		ans[i]=i-a+1;
		update(1, 0, n-1, arr[i].first);
	}
	for(int i=0;i<n; i++) printf("%d\n", ans[i]);
	
}
