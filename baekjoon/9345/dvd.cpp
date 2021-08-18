#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define pii pair<int, int>

int dvd[100000];
vector<pii> segTree;

void initTree(int idx, int s, int e){
	if(s==e) {segTree[idx]={s, s}; return;}
	int mid = (s+e)/2;
	segTree[idx]={s, e};
	initTree(idx*2, s, mid);
	initTree(idx*2+1, mid+1, e);
}

pii getChange(int idx, int s, int e, int l, int r){
	if(l<=s&&e<=r) return segTree[idx];
	if(e<l||r<s) return {100001, -1};
	int mid=(s+e)/2;
	pii lp=getChange(idx*2, s, mid, l, r);
	pii rp=getChange(idx*2+1, mid+1, e, l, r);
	return {min(lp.first, rp.first), max(lp.second, rp.second)};
}

pii change(int idx, int s, int e, int p, int diff){
	if(s>p||e<p) return segTree[idx];
	if(s==e)
		return segTree[idx]={diff, diff};
	else{
		int mid = (s+e)/2;
		pii lp = change(idx*2, s, mid, p, diff);
		pii rp = change(idx*2+1, mid+1, e, p, diff);
		return segTree[idx]={min(lp.first, rp.first), max(lp.second, rp.second)};
	}
}

int main(void){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int n, k;
		scanf("%d %d", &n, &k);
		for(int i=0;i<n; i++) dvd[i]=i;
		segTree.resize(n*4, {0, 0});
		initTree(1, 0, n-1);
		int cidx=1;
		for(int i=0;i<k; i++){
			int q, a, b;
			scanf("%d %d %d", &q, &a, &b);
			if(q==0){
				swap(dvd[a], dvd[b]);
				change(1, 0, n-1, a, dvd[a]);
				change(1, 0, n-1, b, dvd[b]);
			}else{
				pii ans =getChange(1, 0, n-1, a, b);
				if(ans.first==a&&ans.second==b) printf("YES\n");
				else printf("NO\n");
			}
		}
	}
}
