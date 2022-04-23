#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int map[16][16];
int ans[16][16];
int N;

void check(int y, int x, int p){
	if(y<0||x<0||x>=N||y>=N) return ;
	ans[y][x]+=1;
	if(y+1<=N&&x+1<=N&&!map[y+1][x]&&!map[y+1][x+1]&&!map[y][x+1]) check(y+1, x+1, 3);
	if(p==1||p==3)
	{
		if(x+1<=N&&!map[y][x+1]) check(y, x+1, 1);
	}
	if(p==2||p==3)
	{
		if(y+1<=N&&!map[y+1][x]) check(y+1, x, 2);
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N; 
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			cin >> map[i][j];
		}
	}
	check(0, 1, 1);
	cout<< ans[N-1][N-1];
}
