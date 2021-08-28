#include<cstdio>
#include<algorithm>
using namespace std;
int main(void){
	int n;
	scanf("%d",&n);
	int arr[100000];
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
	int maxv=arr[0]*n;
	for(int i=1; i<n; i++){
		maxv=max(maxv, arr[i]*(n-i));
	}
	printf("%d", maxv);
}
