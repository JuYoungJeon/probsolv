#include <cstdio>
#include <algorithm>
using namespace std;
int b[50][50];

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	getc(stdin);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			char t;
			scanf("%c", &t);
			if(t=='W') b[i][j]=0;
			else b[i][j]=1;

		}
		getc(stdin);
	}
	int minChange=n*m;
	for(int i=0; i<=n-8; i++){
		for(int j=0; j<=m-8; j++){
			int numChangeW=0;
			int numChangeB=0;
			for(int k=0; k<8; k++){
				for(int l=0; l<8; l++){
					if(b[i+k][j+l]==(k+l)%2) numChangeB+=1;
					else numChangeW+=1;
				}
			}
			minChange=min(minChange, numChangeB);
			minChange=min(minChange, numChangeW);
		}
	}
	printf("%d", minChange);
}
//Note : char 받을 때 \n 조심하기
