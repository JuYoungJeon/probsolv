#include <iostream>
#include <vector>
using namespace std;
//1 up, 2 down, 3 right, 4 left
int dir[4][2]={{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int ocean[100][100]={0};
struct shark {
	int y, x;
	int speed;
	int dir;
	int size;
};
vector<shark> sharks;

void printOcean(int r, int c, int m){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cout << ocean[i][j] <<' ';
		}
		cout <<'\n';
	}
}

int solution(int r, int c, int m){
	int catchedSize=0;
	//fisher move right
	for(int i=0; i< c; i++){
		//fish
		for(int j=0; j<r; j++){
			if(ocean[j][i]>=0) {
				catchedSize+=sharks[ocean[j][i]].size;
				sharks[ocean[j][i]].y=-1;
				ocean[j][i]=-1;
				break;
			}
		}
		//move the sharks
		for(int j=0; j<m; j++){
			if (sharks[j].y ==-1) continue;
			//up,down
			if(ocean[sharks[j].y][sharks[j].x]==j)
				ocean[sharks[j].y][sharks[j].x]=-1;
			int dist = sharks[j].speed;
			int oneround;
			if(sharks[j].dir>2){
				oneround = (c-1)*2;
			}else{
				oneround = (r-1)*2; }
			int numRounds = dist/oneround;
			dist -= (numRounds*oneround);
			while(dist>0){
				dist-=1;
				int next_y = sharks[j].y+dir[sharks[j].dir-1][0];
				int next_x = sharks[j].x+dir[sharks[j].dir-1][1];
				if(next_y<0||next_y>=r||next_x<0||next_x>=c){
					if(sharks[j].dir==1||sharks[j].dir==3) sharks[j].dir+=1;
					else sharks[j].dir-=1;
				}
				sharks[j].y+=dir[sharks[j].dir-1][0];
				sharks[j].x+=dir[sharks[j].dir-1][1];
			}

			if(ocean[sharks[j].y][sharks[j].x]!=-1&&ocean[sharks[j].y][sharks[j].x]<j){
				// if existing shark in that block is larger
				if((sharks[ocean[sharks[j].y][sharks[j].x]]).size > sharks[j].size){
					sharks[j].y=-1; sharks[j].x=-1;
				}else{
					sharks[ocean[sharks[j].y][sharks[j].x]].y=-1;
					sharks[ocean[sharks[j].y][sharks[j].x]].x=-1;
					ocean[sharks[j].y][sharks[j].x]=j;
				}
			}else {
				ocean[sharks[j].y][sharks[j].x]=j;
			}

		}

	}
	return catchedSize;
}

int main(void){
	int r, c, m;
	cin >> r >> c >> m;
	memset(ocean, -1, sizeof(ocean));
	for (int i=0; i<m; i++){
		int y, x, s, d, z;
		cin >> y >> x>>s>>d>>z;
		shark new_shark = {y-1, x-1, s, d, z};
		sharks.push_back(new_shark);
		ocean[y-1][x-1]=i;
	}
	cout << solution(r, c, m);
}
