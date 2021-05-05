#include<cstdio>
#include<cstdlib>
#define P 1000
int* matrix[5];
int* tmpMat[5];
int** matMult(int** mat, int** mat2, int n){
	for(int i=0; i<n ;i++){
		for(int j=0; j<n; j++){
			int t=0;
			for(int k=0; k<n; k++){
				t+=(mat[i][k]*mat2[k][j]);
			}
			tmpMat[i][j]=t%P;
		}
	}
	return tmpMat;
}
int** matPow(int n, long long m){
	if(m==1) return matrix;
	int** res=0;
	res=new int*[n];
	for(int i=0; i<n; i++){
		res[i]=(int*)malloc(n*sizeof(int));
	}
	int **t;
	if(m%2==0){
		t=matPow(n, m/2);
		t=matMult(t, t, n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
				res[i][j]=t[i][j]%1000;
		}
	}else{
		t=matPow(n, m-1);
		t=matMult(t, matrix, n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
				res[i][j]=t[i][j]%1000;
		}
	}
	return res;
}
int main(void){
	int n;
	long long b;
	scanf("%d %lld", &n, &b);
	for(int i=0; i<n; i++){
		matrix[i]=(int*)malloc(n*sizeof(int));
	}
	for(int i=0; i<n; i++){
		tmpMat[i]=(int*)malloc(n*sizeof(int));
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	int** ans=matPow(n, b);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
}
//2d Array init
//local / global difference
