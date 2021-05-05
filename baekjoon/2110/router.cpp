#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int dist[200000];
int main(void){
	int n, c;
	scanf("%d %d", &n, &c);
	for(int i=0; i<n; i++){
		scanf("%d", &dist[i]);
	}
	sort(dist, dist+n);
	int lo=0, hi=dist[n-1]-dist[0];
	int mid;
	int ans=0;
	while(lo<=hi){
		mid=(lo+hi)/2;
		int cnt=1;
		int before=0;
		for(int i=0; i<n; i++){
			if(dist[i]-dist[before]>=mid) {
				before=i;
				cnt+=1;
			}
		}
		if(cnt>=c) ans=max(ans, mid);
		if(cnt<c)hi=mid-1;
		else lo=mid+1;
	}
	printf("%d", ans);
}
//Note: when using binary search think of what to search.. 
