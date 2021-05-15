#include<cstdio>
#include<algorithm>
using namespace std;
int C[1000000];
int A[1000000];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0;i<N; i++)
		scanf("%d", &A[i]);
	int cl=0;
	C[0]=A[0];
	for(int i=1; i<N; i++){
		if(A[i]>C[cl]) {cl++; C[cl]=A[i];}
		else{
			int a=lower_bound(C, C+cl, A[i])-C;
			C[a]=A[i];
		}
	}
	printf("%d", cl+1);
}
