#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	int have[500000];
	for(int i=0; i<n; i++)
		scanf("%d", &have[i]);
	int m;
	int req[500000];
	scanf("%d", &m);
	for(int j=0; j<m; j++)
		scanf("%d", &req[j]);
	int ans[500000];
	memset(ans, 0, sizeof(ans));
	sort(have, have+n);
	for(int i=0; i<m; i++){
		int h=n, l=0;
		int mid;
		while(h>=l){
			mid=(h+l)/2;
			if(have[mid]==req[i]){
				if(mid==0||have[mid-1]!=req[i]) break;
			}
			if(have[mid]>=req[i])h=mid-1;
			else l=mid+1;
		}
		if(h<l) ans[i]=0;
		else{
			int h=n-1, l=mid+1;
			int m;
			while(h>=l){
				m=(h+l)/2;
				if(have[m]==req[i]){
					if(m+1==n||have[m+1]!=req[i]) {m+=1;break;}
				}
				if(have[m]>req[i]) h=m-1;
				else l=m+1;
			}
			ans[i]=m-mid;
		}
	}
	for(int i=0; i<m; i++){
		printf("%d ", ans[i]);
	}
}
//Note: algorithm의 lower_bound, upper_bound 사용..
