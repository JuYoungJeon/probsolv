#include<cstdio>
#include<cstring>
int map[2187][2187];
int ans[3];
bool checkColor(int y, int x, int m){
	for(int i=0; i<m; i++)
		for(int j=0; j<m; j++)
			if(map[y+i][x+j]!=map[y][x]) return false;
	ans[map[y][x]+1]+=1;
	return true;
}
void divide(int y, int x, int m){
	if(checkColor(y, x, m)) return;
	for(int i=0; i<3; i++){
		for(int j=0;j<3; j++){
			divide(y+i*m/3, x+j*m/3, m/3);
		}
	}
}

int main(void){
	int n;
	scanf("%d", &n);
	memset(map, 0, sizeof(map));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]); 
		}
	}
	divide(0, 0, n);
	for(int i=0; i<3; i++)
		printf("%d\n", ans[i]);
}
