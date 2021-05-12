#include<cstdio>
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	int num[10000];
	for(int i=0;i <n; i++)
		scanf("%d", &num[i]);
	int s=0, e=0;
	int ans=0;
	int sum=num[s];
	while(e<n){
		if(sum<m){
			e+=1;
			sum+=num[e];
		}else if(sum>=m){
			if(sum==m) ans+=1;
			sum-=num[s];
			s+=1;
		}
	}
	printf("%d", ans);
}
