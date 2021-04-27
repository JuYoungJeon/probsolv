#include<cstdio>
using namespace std;
int main(void){
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);
	int c=v-a;
	int ans;
	if(c%(a-b)!=0) printf("%d", c/(a-b)+2);
	else printf("%d", c/(a-b)+1);
}
