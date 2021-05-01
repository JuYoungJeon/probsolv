#include<cstdio>
#include <algorithm>
#include<cstring>
using namespace std;
int ans=0;
int check[15][2];
int checkDig[30][2];
void put(int y, int n, int left){
	if(left==0) {ans+=1; return;}
	for(int j=0; j<n; j++){
		if(check[y][0]||check[j][1]) continue;
		if(checkDig[y+j][0]||checkDig[y-j+n-1][1]) continue;
		check[y][0]=1, check[j][1]=1;
		checkDig[y+j][0]=1, checkDig[y-j+n-1][1]=1;
		put(y+1, n, left-1);
		check[y][0]=0, check[j][1]=0;
		checkDig[y+j][0]=0, checkDig[y-j+n-1][1]=0;
	}
}

int main(){
	int n; 
	scanf("%d", &n);
	memset(check, 0, sizeof(check));
	memset(checkDig, 0, sizeof(checkDig));
	put(0, n, n);
	printf("%d", ans);
}
//Note: NQueen 은 같은 행/열/대각선에는 넣지않는다 행렬대각선을 하나의 list로 표현
