#include<cstdio>
using namespace std; 
int map[128][128];
int blue=0, white=0;
bool checkColor(int y, int x, int m){
	for(int i=0; i<m; i++)
		for(int j=0; j<m; j++)
			if(map[y+i][x+j]!=map[y][x]) return false;
	if(map[y][x]==0) white+=1;
	else blue+=1;
	return true;
}
void divide(int y, int x, int m){
	if(checkColor(y, x, m)) return;
	divide(y, x, m/2);
	divide(y+m/2, x, m/2);
	divide(y, x+m/2, m/2);
	divide(y+m/2, x+m/2, m/2);
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &(map[i][j]));
	divide(0, 0, n);
	printf("%d\n", white);
	printf("%d", blue);
}
