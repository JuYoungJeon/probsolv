#include<cstdio>
#include<cmath>
using namespace std;
int map[51][51];
int s, N, K, R1, R2, C1, C2;
void makeBlack(int y1, int x1, int y2, int x2){
	for(int i=y1; i<=y2; i++){
		for(int j=x1; j<=x2; j++){
			if(i>=R1&&i<=R2&&j>=C1&&j<=C2) map[i-R1][j-C1]=1;
		}
	}
}
void divCon(int cs, int y1, int x1, int y2, int x2){
	if(cs==0) return;
	if(y2<R1||y1>R2||x2<C1||x1>C2) return;
	int mid=(N-K)/2;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int next = pow(N, cs-1);
			if(i>=mid&&j>=mid&&i<=N-mid-1&&j<=N-mid-1){
				makeBlack(y1+i*next, x1+j*next, y1+(i+1)*next-1, x1+(j+1)*next-1);
			}else {
				divCon(cs-1, y1+i*next, x1+j*next, y1+(i+1)*next-1, x1+(j+1)*next-1);
			}
		}
	}
}
int main(void){
	scanf("%d %d %d %d %d %d %d", &s, &N, &K, &R1, &R2, &C1, &C2);
	int size = pow(N, s);
	divCon(s, 0, 0, size-1, size-1);
	for(int i=0; i<=R2-R1; i++){
		for(int j=0; j<=C2-C1; j++){
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
}
