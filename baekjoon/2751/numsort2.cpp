#include<cstdio>
#include<cstring>
using namespace std;
int main(void){
	int n; 
	int counting[10001];
	memset(counting, 0, sizeof(counting));
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int t;
		scanf("%d", &t);
		counting[t]+=1;
	}
	for(int i=0; i<10001; i++){
		while(counting[i]){ 
			printf("%d\n", i);
			counting[i]-=1;
		}
	}
}
//Note : counting sort ->O(n) but depends on the range of the input
