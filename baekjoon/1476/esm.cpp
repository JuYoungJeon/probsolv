#include<cstdio>
using namespace std;

int main(void){
	int ae,as,am;
	scanf("%d %d %d", &ae, &as, &am);
	int ans=1;
	int e=1, s=1, m=1;
	while(!(e==ae&&s==as&&m==am)){
		ans+=1;
		e+=1; m+=1; s+=1;
		if(e>15) e=1;
		if(m>19) m=1;
		if(s>28) s=1;
	}
	printf("%d", ans);
}
