#include <cstdio>
using namespace std;
int sorted[1000];
int list[1000];

void merge(int l, int m, int r){
	int i=l, j=m+1, k=l;
	while(i<=m &&j<=r){
		if(list[i]<list[j]){
			sorted[k]=list[i];
			i+=1;k+=1;
		}else{
			sorted[k]=list[j];
			j+=1;k+=1;
		}
	}
	if(i>m){
		while(j<=r){
			sorted[k]=list[j];
			k++; j++;
		}
	}else{
		while(i<=m){
			sorted[k]=list[i];
			k++; i++;
		}
	}
	for(int i=l; i<=r; i++)
		list[i]=sorted[i];
}

void merge_sort(int l, int r){
	int m=(l+r)/2;
	if(l<r){
		merge_sort(l, m);
		merge_sort(m+1, r);
		merge(l, m, r);
	}
}
int main(void){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &list[i]);
	merge_sort(0, n-1);
	for(int i=0; i<n; i++)
		printf("%d\n", list[i]);
}
