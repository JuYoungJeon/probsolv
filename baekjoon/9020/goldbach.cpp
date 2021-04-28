#include<cstdio>
#include<cstring>
using namespace std;
int main(void){
	int isPrime[10001];
	memset(isPrime, 0, sizeof(isPrime));
	isPrime[1]=-1;
	for(int i=2; i<=10000; i++){
		int j=2;
		while(j*i<=10000){ isPrime[i*j]=-1; j+=1;}
	}
	int tc; 
	scanf("%d", &tc);
	for(int i=0; i<tc; i++){
		int n;
		scanf("%d", &n);
		int minDiff[2]={0, n};
		for(int j=2; j<=n/2; j++){
			if(!isPrime[j]&&!isPrime[n-j]){//&&(n-2*j)<minDiff[1]-minDiff[0]){
				minDiff[0]=j;
				minDiff[1]=n-j;
			}
		}
		printf("%d %d\n", minDiff[0], minDiff[1]);
	}
}
