#include<cstdio>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	int a[1000000];
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int b, c;
	scanf("%d %d", &b, &c);
	long long ans=0;
	for(int i=0; i<n; i++){
		ans+=1;
		a[i]-=b;
		if(a[i]<1) continue;
		if(a[i]%c==0)
			ans+=a[i]/c;
		else ans+=a[i]/c+1;
	}
	printf("%lld", ans);
	
}
