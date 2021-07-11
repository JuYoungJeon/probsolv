#include<cstdio>
#include<algorithm>
using namespace std;
int arr[40000];
int lis[40000];

int main(void){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	int last=0;
	lis[0]=arr[0];
	for(int i=1; i<n; i++){
		if(lis[last]<arr[i]){
			last++;
			lis[last]=arr[i];
		}else{
			int idx=lower_bound(lis, lis+last+1, arr[i])-lis+1;
			lis[idx-1]=arr[i];
		}
	}
	printf("%d", last+1);
}
