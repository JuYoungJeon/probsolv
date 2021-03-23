#include <iostream>

using namespace std;

const int blockXd[4][3]={{0,1,1},{0,1,0},{0,0,1},{0,-1,0}};
const int blockYd[4][3]={{0,0,1},{0,0,1},{0,1,1},{0,1,1}};

void printBoard (int h, int w, int board[20][20]){
	for (int i=0; i<h; i++){
		for (int j=0; j<w; j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}

bool checkCovered(int h, int w, int board[20][20]){
	bool done=true;
	for (int i=0; i<h; i++){
		for (int j=0; j<w; j++){
			if(board[i][j]==0) done=false;
		}
	}
	return done;
}

int putBlock(int h, int w, int board[20][20], int y, int x){
	int ans=0;
	//cout <<"BEFORE " << y << x << '\n';
	//printBoard(h, w, board);
	if (y < 0 || y >= h || x <0 || x >= w) return 0;
	if( y== h-1){
		if (checkCovered(h, w, board)) return 1;
	}
	if (y == h-2 && x== w-1){
		if(checkCovered(h, w, board)) return 1;
	}
	for (int i=0; i<4; i++){
		bool fitIn=true;
		for (int j=0; j<3; j++){
			if (y+ blockYd[i][j] >= h)
				fitIn=false;
			if (x + blockXd[i][j] < 0 || x+ blockXd[i][j] >= w)
				fitIn=false;
			if(board[y+blockYd[i][j]][x+blockXd[i][j]]==1) fitIn=false;
		}
		if (!fitIn) continue;
		for(int j=0; j<3; j++)
			board[y+blockYd[i][j]][x+blockXd[i][j]]=1;

		if (x+1 == w) x=0, y+=1;
        else x+=1;
		//cout << "AFTER: "<< y << x <<'\n';
		//printBoard(h, w, board);
		ans+=putBlock(h, w, board, y, x);
		if (x-1<0) x=w-1, y-=1;
		else x-=1;
		for (int j=0; j<3; j++)
			board[y+blockYd[i][j]][x+blockXd[i][j]]=0;
	}
	if (y<=h-2 && board[y][x]==1){
		if(x+1==w) x=0, y+=1;
		else x+=1;
		ans+=putBlock(h, w, board, y, x);
		if( x-1 <0) x=w-1, y-=1;
		else x-=1;
	}

	return ans;
}

int main(){

	int numTc;
	cin >> numTc; 

	int ans[50];
	for (int i=0; i< numTc; i++){
		int h, w;
		cin >> h >> w;
		//read in board
		int board[20][20];
		for (int j=0; j<h; j++){
			for (int k=0; k<w; k++){
				char block;
				cin >> block;
				if(block=='#') board[j][k]=1;
				if(block=='.') board[j][k]=0;
			}
		}
		ans[i]=putBlock(h, w, board, 0,0);
	}
	for (int i=0; i<numTc; i++)
		cout << ans[i] << '\n';
}
