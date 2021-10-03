#include<iostream>
#include<algorithm>

using namespace std;

int dir[4][2]={{1,0},{0,1}, {-1,0},{0,-1}};
int blocks[20][20];
int N, W, H;

int erase(int ty, int tx){
	int numerase=1;
	int range=blocks[ty][tx];
	blocks[ty][tx]=0;
	for(int i=1;i<range; i++){
		for(int d=0; d<4; d++){
			int dy=ty+dir[d][0]*i;
			int dx=tx+dir[d][1]*i;
			if(dy<0||dx<0||dy>=H||dx>=W) continue;
			if(!blocks[dy][dx]) continue;
			numerase+=erase(dy, dx);
		}
	}
	return numerase;
}

void rearrange(){
	for(int j=0; j<W; j++){
		int zy=-1;
		for(int i=H-1; i>=0; i--){
			if(!blocks[i][j]&&zy==-1){
				zy=i; continue;
			}
			if(blocks[i][j]&&zy!=-1){
				blocks[zy][j]=blocks[i][j];
				blocks[i][j]=0;
				zy--;
			}
		}
	}
}
int dfs(int idx){
	if(idx==N) return 0;
	int original[20][20];
	for(int i=0;i<H; i++){
		for(int j=0;j<W; j++){
			original[i][j]=blocks[i][j];
		}
	} 
	int maxerase=0;
	for(int col=0; col<W; col++){
		int curerase=0;
		int topy=-1;
		for(int i=0; i<H; i++){
			if(blocks[i][col]){
				topy=i; break;
			}
		}
		if(topy==-1) continue;
		curerase+=erase(topy, col);
		rearrange();
		curerase+=dfs(idx+1);
		for(int i=0;i<H; i++){
			for(int j=0;j<W; j++){
				blocks[i][j]=original[i][j];
			}
		}
		maxerase=max(maxerase, curerase);
	}
	return maxerase;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++){
		int total=0;
		cin >> N>>W>>H;
		for(int i=0;i<H; i++){
			for(int j=0;j<W; j++){
				cin>> blocks[i][j];
				if(blocks[i][j]) total+=1;
			}
		}
		int ans=dfs(0);
		cout << '#'<<test_case<<' '<<total-ans<<'\n';
	}
}
