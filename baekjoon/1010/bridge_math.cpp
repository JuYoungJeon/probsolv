#include<cstdio>
int main(void){
	int tc;
	scanf("%d", &tc);
	for(int i=0; i<tc; i++){
		int n, k;
		scanf("%d %d", &k, &n);
		k=k>n-k?n-k:k;
		if(k==0) {printf("1\n"); continue;}
		long long sum=1;
		long long div=1;
		long long ans=1;
		for(int j=0; j<k; j++){
			sum*=n-j;
			div*=k-j;
			if(sum%div==0){ans*=sum/div;sum=1; div=1;}
		}
		printf("%lld\n", ans);
	}

}
//Note 중간 값확인하기(if it execeeds ds range)
