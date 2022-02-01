#include <iostream>

using namespace std;

int N, M;
int board[40][40];
int stickSize[100][2];
int stickers[100][10][10];

bool rotateAndStick(int sidx, int deg){
	int rotated[10][10];
	int rotR, rotC;
	if(deg==0){
		for(int i=0;i<stickSize[sidx][0]; i++){
			for(int j=0;j<stickSize[sidx][1]; j++){
				rotated[i][j]=stickers[sidx][i][j];
			}
		}
		rotR=stickSize[sidx][0];
		rotC=stickSize[sidx][1];
	}else if(deg==1){
		for(int j=0, ni=0; j<stickSize[sidx][1]; j++, ni++){
			for(int i=stickSize[sidx][0]-1, nj=0; i>=0; i--, nj++){
				rotated[ni][nj]=stickers[sidx][i][j];
			}
		}
		rotR=stickSize[sidx][1];
		rotC=stickSize[sidx][0];
	}else if (deg==2){
		for(int i=stickSize[sidx][0]-1, ni=0; i>=0; i--, ni++){
			for(int j=stickSize[sidx][1]-1, nj=0; j>=0; j--, nj++){
				rotated[ni][nj]=stickers[sidx][i][j];
			}
		}
		rotR=stickSize[sidx][0];
		rotC=stickSize[sidx][1];
	}else{
		for(int j=stickSize[sidx][1]-1, ni=0; j>=0; j--, ni++){
			for(int i=0, nj=0; i<stickSize[sidx][0]; i++, nj++){
				rotated[ni][nj]=stickers[sidx][i][j];
			}
		}
		rotR=stickSize[sidx][1];
		rotC=stickSize[sidx][0];
	}
	for(int i=0;i<N; i++){
		for(int j=0;j<M; j++){
			bool occu=false;
			for(int y=0; y<rotR; y++){
				for(int x=0; x<rotC; x++){
					if((i+y>=N||j+x>=M)||(board[i+y][j+x]==1&&rotated[y][x]==1)){
						occu=true;
						break;
					}
				}
				if(occu) break;
			}
			if(!occu){
				for(int y=0;y<rotR; y++){
					for(int x=0; x<rotC; x++){
						if(rotated[y][x])
							board[i+y][j+x]=rotated[y][x];
					}
				}
				return true;
			}
		}
	}
	return false;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K;
	cin >> N >> M >> K;

	for(int i=0;i<K; i++){
		cin >> stickSize[i][0] >> stickSize[i][1];
		for(int y=0; y<stickSize[i][0]; y++){
			for(int x=0; x<stickSize[i][1]; x++){
				cin >> stickers[i][y][x];
			}
		}
	}
	for(int i=0; i<K; i++){
		for(int j=0;j<4; j++){
			bool succ = rotateAndStick(i, j);
			if(succ) break;
		}
	}
	int ans=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(board[i][j]) ans++;
		}
	}
	cout << ans;
}
