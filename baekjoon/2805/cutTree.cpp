#include<cstdio>
#include<algorithm>
using namespace std;
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	int t[1000000];
	for(int i=0;i <n; i++)
		scanf("%d", &t[i]);
	sort(t, t+n);
	int l=0, h=t[n-1];
	int ans=0;
	while(l<=h){
		int mid=(l+h)/2;
		int from=lower_bound(t, t+n, mid)-t;
		long long sum=0;
		for(int i=from; i<n; i++){
			if(t[i]>mid)sum+=(t[i]-mid);
		}
		if(sum>=m){
			ans=max(ans, mid);
		}
		if(sum<m){
			h=mid-1;
		}else{
			l=mid+1;
		}
	}
	printf("%d", ans);
}
