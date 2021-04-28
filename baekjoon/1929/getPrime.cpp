#include<cstdio>
#include<cstring>
using namespace std;
int main(void){
	int a, b;
	scanf("%d %d", &a, &b);
	int res[1000000];
	memset(res, 0, sizeof(res));
	if(a==1) a=2;
	for(int i=2; i<=b; i++){
		int mult=2;
		if(i>=a&&res[i]==0) printf("%d\n", i);
		while(mult*i<=b){ res[mult*i]=-1; mult+=1;}
	}
}
//Note: 소수를 구할때 에라토스네스체를 사용하여 2..b까지 우선 곱이되는 것들을 지우고 나아가기
