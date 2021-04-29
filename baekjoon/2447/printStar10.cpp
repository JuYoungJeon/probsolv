#include<cstdio>
#include<cmath>
using namespace std;
char map[7000][7000];

void printSpace(int y, int x, int n){
	for(int i=0; i<(int)pow(3, n); i++){
		for(int j=0; j<(int)pow(3, n); j++)
			map[y+i][x+j]=' ';
	}
}
void printStar(int y, int x, int n){
	if(n==0) {map[y][x]='*'; return;}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i==1&&j==1){
				continue;
				//printSpace(y+i*(int)pow(3,n-1), x+j*(int)pow(3, n-1), n-1);
			}
			else printStar(y+i*(int)pow(3,n-1), x+j*(int)pow(3,n-1),n-1);
		}
	}
}
int main(void){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n ;j++)
			map[i][j]=' ';
	}
	int value=n;
	int cbroot=0;
	while(value/3!=0) {value/=3; cbroot+=1;}
	printStar(0, 0, cbroot);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
}
//cbrt는 정확하지않음...
