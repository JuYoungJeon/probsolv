#include <iostream>
#include <vector>

using namespace std;
//up, right, down, left
string dir[4]={"up", "right", "down", "left"};
int directions[4][2] ={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int cache[10][10][10][10];

void printBoard(vector<vector<int> > board){
	for(int i=0; i<board.size(); i++){
		for(int j=0; j<board[i].size();j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}

vector<vector<int> > move(int* redLoc, int* blueLoc, vector<vector<int> > board, int dir[2]){
	bool redFirst=false;
		
	if(dir[0]<0 || dir[1]<0){
		if(redLoc[0] < blueLoc[0] || redLoc[1]< blueLoc[1])
			redFirst=true;
	}else{
		if(redLoc[0] > blueLoc[0] || redLoc[1] > blueLoc[1])
			redFirst=true;
	}
	if(redFirst){
		int numMoveY=dir[0], numMoveX=dir[1];
		board[redLoc[0]][redLoc[1]]=0;
		while(board[redLoc[0]+numMoveY][redLoc[1]+numMoveX]==0){
			numMoveY+=dir[0];
			numMoveX+=dir[1];
		}
		if(board[redLoc[0]+numMoveY][redLoc[1]+numMoveX]==3){
			redLoc[0]+=numMoveY;
			redLoc[1]+=numMoveX;
		}else{
			redLoc[0]+=numMoveY-dir[0];
			redLoc[1]+=numMoveX-dir[1];
		}

		if(board[redLoc[0]][redLoc[1]]==0){
			board[redLoc[0]][redLoc[1]]=1;
		}

		numMoveY=dir[0], numMoveX=dir[1];
		board[blueLoc[0]][blueLoc[1]]=0;
		while(board[blueLoc[0]+numMoveY][blueLoc[1]+numMoveX]==0){
			numMoveY+=dir[0];
			numMoveX+=dir[1];
		}
		if (board[blueLoc[0]+numMoveY][blueLoc[1]+numMoveX]==3){
			blueLoc[0]+=numMoveY;
			blueLoc[1]+=numMoveX;
		}else{
			blueLoc[0]+=numMoveY-dir[0];
			blueLoc[1]+=numMoveX-dir[1];
		}
		if(board[blueLoc[0]][blueLoc[1]]==0)
			board[blueLoc[0]][blueLoc[1]]=2;
	}else{
		int numMoveY=dir[0], numMoveX=dir[1];
		board[blueLoc[0]][blueLoc[1]]=0;
		while(board[blueLoc[0]+numMoveY][blueLoc[1]+numMoveX]==0){
			numMoveY+=dir[0];
			numMoveX+=dir[1];
		}
		if (board[blueLoc[0]+numMoveY][blueLoc[1]+numMoveX]==3){
			blueLoc[0]+=numMoveY;
			blueLoc[1]+=numMoveX;
		}else{
			blueLoc[0]+=numMoveY-dir[0];
			blueLoc[1]+=numMoveX-dir[1];
		}
		if(board[blueLoc[0]][blueLoc[1]]==0)
			board[blueLoc[0]][blueLoc[1]]=2;

		numMoveY=dir[0], numMoveX=dir[1];
		board[redLoc[0]][redLoc[1]]=0;
		while(board[redLoc[0]+numMoveY][redLoc[1]+numMoveX]==0){
			numMoveY+=dir[0];
			numMoveX+=dir[1];
		}
		if(board[redLoc[0]+numMoveY][redLoc[1]+numMoveX]==3){
			redLoc[0]+=numMoveY;
			redLoc[1]+=numMoveX;
		}else{
			redLoc[0]+=numMoveY-dir[0];
			redLoc[1]+=numMoveX-dir[1];
		}
		if(board[redLoc[0]][redLoc[1]]==0)
			board[redLoc[0]][redLoc[1]]=1;

	}
	return board;
}

int solution(int ans, int* redLoc, int* blueLoc, vector<vector<int> > board, int ith){
	int& ret = cache[redLoc[0]][redLoc[1]][blueLoc[0]][blueLoc[1]];
	//cout << redLoc[0] << redLoc[1] << '\n';
	//cout << blueLoc[0] << blueLoc[1] << '\n';
	//cout << ret << '\n';
	if (ret !=-1 && ret <= ith) return 11;
	else ret = ith;
	if (ans<=ith)return 11;
	if(ith==11) return 11;
	if(board[blueLoc[0]][blueLoc[1]]==3) return 11;
	if(board[redLoc[0]][redLoc[1]]==3&&board[blueLoc[0]][blueLoc[1]]!=3) return ith;
	for (int i=0; i<4; i++){
		vector<vector<int> > new_board = board;
		int prevRedLoc[2]={redLoc[0], redLoc[1]};
		int prevBlueLoc[2]={blueLoc[0], blueLoc[1]};
		board= move(redLoc, blueLoc, board, directions[i]);
		ans = min(ans, solution(ans, redLoc, blueLoc, board, ith+1));
		redLoc[0] = prevRedLoc[0], redLoc[1] = prevRedLoc[1];
		blueLoc[0] = prevBlueLoc[0], blueLoc[1]= prevBlueLoc[1];
		board=new_board;
	}
	return ans;
}

int main(void){
	int col, row;
	cin >> row >> col;

	vector<vector<int> > board ;

	int redLoc[2], blueLoc[2];
	char inputVal;
	memset(cache, -1, sizeof(cache));
	for(int i=0; i<row; i++){
		vector<int> t;
		for(int j=0; j<col; j++){
			cin >> inputVal;
			if (inputVal == 'R') {
				t.push_back(1);
				redLoc[0]= i, redLoc[1]=j;
			}
			if (inputVal == 'B') {
				t.push_back(2);
				blueLoc[0]=i, blueLoc[1]=j;
			}
			if (inputVal =='O') t.push_back(3);
			if (inputVal == '.') t.push_back(0);
			if (inputVal == '#') t.push_back(-1);
		}
		board.push_back(t);
	}
	int ans = solution(11, redLoc, blueLoc, board,0);
	if (ans==11) ans=-1;
	cout << ans;

}
