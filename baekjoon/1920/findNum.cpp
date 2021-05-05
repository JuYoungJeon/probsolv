#include<cstdio>
#include<algorithm>
using namespace std;
int main(void){
	int n; 
	scanf("%d", &n);
	int num[100000];
	for(int i=0; i<n; i++){
		scanf("%d", &num[i]);
	}
	int fn;
	int fnum[100000];
	scanf("%d", &fn);
	for(int i=0; i<fn; i++)
		scanf("%d", &fnum[i]);
	sort(num, num+n);
	for(int i=0; i<fn; i++){
		int h=n-1, l=0;
		int mid=(h+l)/2;
		while(h>=l){
			mid=(h+l)/2;
			if(num[mid]==fnum[i]) break;
			if(num[mid]<fnum[i]) l=mid+1;
			else h=mid-1;
		}
		if(h<l) printf("0\n");
		else printf("1\n");
	}

}
