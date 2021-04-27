#include <cstdio>

using namespace std;
int main(void){
	int tc;
	scanf("%d", &tc);
	for(int i=0; i<tc; i++){
		int h, w, n;
		scanf("%d %d %d", &h, &w, &n);
		int f;
		int r;
		if(n%h!=0){r=n/h+1; f=n%h;}
		else {r=n/h; f=h;}
		if(r<10) printf("%d0%d\n", f,r);
		else printf("%d%d\n", f,r);
	}
}
