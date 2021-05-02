#include<cstdio>
using namespace std;
int main(void){
	int n;
	int all[50];
	scanf("%d", &n);
	int ans;
	ans=1;
	int minV=1000000, maxV=0;
	for(int i=0; i<n ;i++){
		scanf("%d", &all[i]);
		minV=minV>all[i]?all[i]:minV;
		maxV=maxV<all[i]?all[i]:maxV;
	}
	ans=minV*maxV;
	printf("%d", ans);

}
