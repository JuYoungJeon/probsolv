#include<cstdio>
#include<algorithm>
using namespace std;
int A[100000];
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) scanf("%d", &A[i]);
	sort(A, A+n);
	int l=0; int r=0;
	int ans=A[n-1]-A[0];
	int curr= A[r]-A[l];
	while(ans!=m&&l<=r && r<n){
		curr=A[r]-A[l];
		if(curr>=m) {
			ans=min(ans, curr);
			if(l==r) r+=1;
			else l+=1;
		}else{
			r+=1;
		}
	}
	printf("%d", ans);
}
