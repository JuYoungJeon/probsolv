#include <iostream>
#include <vector>

using namespace std;
//up, right, down, left
const string dir_name[4]={"up", "right", "down", "left"};
int direction[4][2]={{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; 

int check_max(int n, vector<vector<int> > b){
	int max=0; 
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if(b[i][j]> max)
				max=b[i][j];
		}
	}
	return max;
}

void printBoard(vector<vector<int> > b){
	for (int i=0; i< b.size(); i++){
		for(int j=0; j<b.size(); j++){
			cout << b[i][j] << ' ';
		}
		cout<< '\n';
	}
}

vector<vector<int> > move(vector<vector<int> > b, int dir[2]){
	int startY = dir[0]>0? b.size()-1:0;
	int startX = dir[1]>0? b.size()-1:0;

	//perline
	for (int i=0; i<b.size(); i++){
		int nextY = startY+-1*dir[0];
		int nextX = startX+-1*dir[1];
		for (int j=1; j<b.size(); j++){
			//cout << startY << ',' << startX<< '\n';
			//cout << nextY << ',' << nextX << '\n';
			if (b[nextY][nextX]==0){
				nextY-=dir[0];
				nextX-=dir[1];
				continue;
			}
			if(b[startY][startX]==b[nextY][nextX]){
				b[startY][startX]*=2;
				startY+=(-1*dir[0]);
				startX+=(-1*dir[1]);
			}
			else if(b[startY][startX]!=0){
				startY+=(-1*dir[0]);
				startX+=(-1*dir[1]);

				if(startY==nextY && startX==nextX) {
					nextY-=dir[0];
					nextX-=dir[1];
					continue;
				}
				b[startY][startX]=b[nextY][nextX];
			}else{
				b[startY][startX]=b[nextY][nextX];
			}
			b[nextY][nextX]=0;
			nextY-=dir[0];
			nextX-=dir[1];
			//printBoard(b);

		}
		if (dir[0]==0)
			startY+=1;
		else
			startY=dir[0]>0? b.size()-1:0;
		if (dir[1]==0)
			startX+=1;
		else
			startX=dir[1]>0? b.size()-1:0;
	}
	return b;
			
}

int solution(int n, vector<vector<int> >b, int move_idx){
	//cout << move_idx <<'\n';
	int cur_max=0;
	if (move_idx==5) return check_max(n, b);

	for(int i=0; i< 4; i++){
		// move toward direction
		vector<vector<int> > new_board = b;
		//cout << move_idx << ' ' << dir_name[i]<<'\n';
		b = move(b, direction[i]);
		//printBoard(b);
		// next move
		cur_max = max(cur_max, solution(n, b, move_idx+1));
		b = new_board;
	}
	return cur_max;
}


int main(void){
	int n;
	vector<vector<int> > board;
	cin >> n;
	for (int i=0; i<n; i++){
		vector<int> t;
		for(int j=0; j<n; j++){
			int tmp;
			cin >> tmp;
			t.push_back(tmp);
		}
		board.push_back(t);
	}

	cout << solution(n, board, 0); 
}
