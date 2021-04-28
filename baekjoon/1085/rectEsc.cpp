#include<cstdio>
#include<algorithm>
using namespace std;
int main(void){
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int minV=w>h?w:h;
	minV=min(minV, w-x);
	minV=min(minV, x);
	minV=min(minV, h-y);
	minV=min(minV, y);
	printf("%d", minV);
}

