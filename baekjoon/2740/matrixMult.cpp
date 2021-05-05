#include<cstdio>
#include<cstring>
int mat1[100][100];
int mat2[100][100];
int ans[100][100];

void mult(int y1, int x1, int y2, int x2){
	for(int i=0; i<y1; i++){
		int block=0;
		for(int j=0; j<x2; j++){
			int t=0;
			for(int k=0; k<y2; k++){
				t+=mat1[i][k]*mat2[k][j];
			}
			ans[i][j]=t;
		}
	}
}

int main(void){
	int y1, x1, y2, x2;
	scanf("%d %d", &y1, &x1);
	for(int i=0; i<y1; i++){
		for(int j=0; j<x1; j++){
			scanf("%d", &mat1[i][j]);
		}
	}
	scanf("%d %d", &y2, &x2);
	for(int i=0; i<y2; i++){
		for(int j=0;j<x2; j++){
			scanf("%d", &mat2[i][j]);
		}
	}
	mult(y1, x1, y2, x2);
	for(int i=0; i<y1; i++){
		for(int j=0; j<x2; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
}
