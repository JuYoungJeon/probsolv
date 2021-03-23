#include <iostream>
#include <vector>
using namespace std;

const int direction[4][2]={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void printBoard(int r, int c, vector<vector<int> > b){
	for (int i=0; i< r; i++){
		for(int j=0; j<c; j++){
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}
}

vector <vector<int> > spread(int r, int c, int puriY, int puriX, vector<vector<int> > b){
	vector <vector<int> > new_b(r, vector<int>(c)); 
	for (int i=0; i< r; i++){
		for (int j=0; j<c; j++){
			if(b[i][j]!=0){
				new_b[i][j]+=b[i][j];
				int cnt=0; 
				for(int k=0; k< 4; k++){
					int targetY=i+direction[k][0];
					int targetX=j+direction[k][1];
					if ((targetY>=0 && targetY<r) && (targetX>=0 && targetX<c) && (targetY!=puriY || targetX!=puriX) && (targetY!=puriY+1 || targetX!=puriX)){
						new_b[targetY][targetX]+=int(b[i][j]/5);
						cnt+=1;
					}
				}
				new_b[i][j]-=cnt*int(b[i][j]/5);
			}
		}
	}
	return new_b;
}

int puri_dir[4][2]={{-1,0},{0, 1}, {1, 0}, {0, -1}};

vector <vector<int> > purify(int r, int c, int puriY, int puriX, vector<vector<int> > b){
	int dx=puriX, dy=puriY;
	for(int i=0; i<2; i++){
		int dir_idx=0;
		dy+=puri_dir[dir_idx][0];
		dx+=puri_dir[dir_idx][1];
		while(dx!=puriX || dy!=(puriY+i)){
			int before_dy=dy-puri_dir[dir_idx][0];
			int before_dx=dx-puri_dir[dir_idx][1];
			if(dy<0 || dx<0 || dy>=r || dx>= c ||(i==0&&dy>puriY)||(i==1&&dy<puriY+1)){

				dx=before_dx, dy=before_dy;
				dir_idx+=1;
			}else if(b[before_dy][before_dx]!=-1){
				b[before_dy][before_dx] = b[dy][dx];
			}
			dy+=puri_dir[dir_idx][0];
			dx+=puri_dir[dir_idx][1];
		}
		b[dy-puri_dir[dir_idx][0]][dx-puri_dir[dir_idx][1]]=0;
		dy=puriY+1, dx=puriX;
		for (int j=0; j<4; j++)
			puri_dir[j][0]*=-1;
	}
	return b;
}

int count_dust(int r, int c, vector<vector<int> > b){
	int cnt=0; 
	for (int i=0; i< r; i++)
		for (int j=0; j<c; j++)
			if (b[i][j]!=-1)
				cnt+=b[i][j];
	return cnt;
}


int solution(int r, int c, int t, int puriY, int puriX, vector<vector <int> > board){
	for (int i=0; i<t; i++){
		//spread();
		board= spread(r, c, puriY, puriX, board);
		//purify();
		board = purify(r, c, puriY, puriX, board);
	}
	int ans = count_dust(r, c, board);
	return ans;
}

int main(){
	int r, c, t; 
	cin >> r >> c >> t;

	vector<vector<int> >board;
	int puriY=-1, puriX=-1;
	for (int i=0; i< r; i++){
		vector <int> tmp;
		for (int j=0; j<c; j++){
			int t;
			cin >> t; 
			tmp.push_back(t);
			if (t ==-1 && puriY==-1){
				puriY=i, puriX=j;
			}
		}
		board.push_back(tmp);
	}
	
	cout << solution(r, c, t, puriY, puriX, board);
}
