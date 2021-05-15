#include<cstdio>
long long ** mult(long long ** t, long long ** f){
	long long** newf=new long long*[2];
	newf[0]=new long long[2]; newf[1]=new long long[2];
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			newf[i][j]=0;
			for(int k=0; k<2; k++){
				newf[i][j]=(newf[i][j]+(t[i][k]*f[k][j])%1000000007)%1000000007;
			}
		}
	}
	return newf;
}
long long ** fib(long long n, long long ** f){
	long long **t;
	if(n==1) return f;
	if(n%2==0){
		t=fib(n/2, f);
		t=mult(t, t);
	}else{
		t=fib(n-1, f);
		t=mult(t, f);
	}
	return t;
}

int main(void){
	long long n;
	scanf("%lld", &n);
	long long** f=new long long*[2];
	f[0]=new long long[2]; f[1]=new long long[2];
	f[0][0]=1; f[0][1]=1; f[1][0]=1; f[1][1]=0;
	long long ** t=fib(n, f);
	printf("%lld", t[0][1]);

}
