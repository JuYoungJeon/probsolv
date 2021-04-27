#include <cstdio>

using namespace std;

int main(void){
	int n;
	int i=1;
	scanf("%d", &n);
	while(i*(i+1)/2<n)	i+=1;
	int nomin, denomin;
	if(i%2==1){
		nomin=i;
		denomin=1;
	}else{
		nomin=1;
		denomin=i;
	}
	int idx=i*(i-1)/2+1;
	while(idx<n){
		if(i%2==1){nomin-=1; denomin+=1;}
		else{nomin+=1; denomin-=1;}
		idx+=1;
	}
	printf("%d/%d", nomin, denomin);
}
