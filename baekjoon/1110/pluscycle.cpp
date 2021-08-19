#include<cstdio>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	int orig=n;
	int newnum=-1;
	int ans=0;
	while(orig!=newnum){
		int plus=n%10+n/10;
		newnum=(n%10)*10+plus%10;
		n=newnum;
		ans+=1;
	}
	printf("%d", ans);
}
