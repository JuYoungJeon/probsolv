#include<cstdio>
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	int f=0; long long mf=5;
	int t=0; long long mt=2;
	while(n>=mf){
		f+=n/mf;
		mf*=5;
	}
	while(n>=mt){
		t+=n/mt;
		mt*=2;
	}
	int nf=0; mf=5;
	int nt=0; mt=2;
	while(m>=mf){
		nf+=m/mf;
		mf*=5;
	}
	while(m>=mt){
		nt+=m/mt;
		mt*=2;
	}	
	mf=5; mt=2;
	while(n-m>=mf){
		nf+=(n-m)/mf;
		mf*=5;
	}
	while(n-m>=mt){
		nt+=(n-m)/mt;
		mt*=2;
	}
	int ans=f-nf<t-nt?f-nf:t-nt;
	printf("%d",ans);
}
//Note: 5개의개수 뿐아니라 2의 개수도 세주기
//제곱을 나누어 갯수세기
