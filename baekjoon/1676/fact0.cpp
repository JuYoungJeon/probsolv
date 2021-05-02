#include<cstdio>

int main(void){
	int n;
	scanf("%d", &n);
	int div=0;
	for(int i=1; i<=n; i++){
		int tar=i;
		while(tar!=0&&tar%5==0) { tar/=5; div++;}
	}
	printf("%d", div);
}
//Note 0!는 1이다
//5의 개수 25의경우 5가 두개
