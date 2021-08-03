#include<cstdio>
#include<cmath>

using namespace std;
int map[51][51];
int s, N, K, R1, R2, C1, C2;
int checkMid(int y, int x, int m){
	int s = ((N-K)/2)*m;
	int e = s+(K*m);
	if(s<=x&&x<e&&s<=y&&y<e) return 1;
	else return 0;
}

int getcolor(int y, int x, int m){
	if(m==1) return 0;
	if(checkMid(y, x, m/N)) return 1;
	return getcolor(y%(m/N), x%(m/N), m/N);
}

int main(void){
	scanf("%d %d %d %d %d %d %d", &s, &N, &K, &R1, &R2, &C1, &C2);
	int m=pow(N, s);
	for(int i=R1; i<=R2; i++){
		for(int j=C1; j<=C2; j++){
			//getcolor(i, j, m/N);
			printf("%d", getcolor(i, j, m));
		}
		printf("\n");
	}
}

