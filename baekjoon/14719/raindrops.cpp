#include<cstdio>
using namespace std;
int main(void){
	int h, w;
	scanf("%d %d", &h, &w);
	int m[500];
	for(int i=0; i<w; i++) scanf("%d", &m[i]);
	int ans=0;
	int startIdx, endIdx;
	startIdx=0;
	for(int i=1; i<w; i++){
		if(m[i]>=m[startIdx]) {
			for(int j=startIdx; j<i; j++){ans+=m[startIdx]-m[j];}
			startIdx=i;
		}
	}
	startIdx=w-1;
	for(int i=w-2; i>=0; i--){
		if(m[i]>m[startIdx]){
			for(int j=startIdx; j>i; j--){ans+=m[startIdx]-m[j];}
			startIdx=i;
		}
	}
	printf("%d", ans);
}
