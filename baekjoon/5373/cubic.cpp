#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class side{
	private:
		vector<vector<char> > color;
		side* up;
		side* down;
		side* right;
		side* left;
	public:
		side(char col){
			for(int i=0;i <3; i++)
				color.push_back(vector<char>(3, col));
		}
		side* getUp(){
			return up;
		}
		vector<vector<char> > getColor(){
			return color;
		}
		void setColor(vector<vector<char> >nc){
			color = nc;
		}
		void setUp(side* u){
			up=u;
		}
		void setDown(side* d){
			down=d;
		}
		void setRight(side* r){
			right=r;
		}
		void setLeft(side* l){
			left=l;
		}
		void rotate(char s, char dir, int num,bool BF){
			if(!BF&&num==4) return;
			if(s=='B'){
				vector<vector<char> > upColor = up->getColor();
				vector<vector<char> > rightColor = right->getColor();
				vector<vector<char> > leftColor = left->getColor();
				vector<vector<char> > downColor = down->getColor();
				for(int i=0;i<3; i++){
					if(dir=='-'){
						upColor[0][i]=left->getColor()[2-i][0];
						leftColor[i][0]=down->getColor()[2][i];
						downColor[2][i]=right->getColor()[2-i][2];
						rightColor[i][2]=up->getColor()[0][i];
					}else{
						upColor[0][i]=right->getColor()[i][2];
						rightColor[i][2]=down->getColor()[2][2-i];
						downColor[2][i]=left->getColor()[i][0];
						leftColor[i][0]=up->getColor()[0][2-i];
					}
				}
				up->setColor(upColor);
				down->setColor(downColor);
				right->setColor(rightColor);
				left->setColor(leftColor);
			}
			if(s=='F'){
				vector<vector<char> > upColor = up->getColor();
				vector<vector<char> > rightColor = right->getColor();
				vector<vector<char> > leftColor = left->getColor();
				vector<vector<char> > downColor = down->getColor();
				for(int i=0;i<3; i++){
					if(dir=='+'){
						upColor[2][i]=left->getColor()[2-i][2];
						leftColor[i][2]=down->getColor()[0][i];
						downColor[0][i]=right->getColor()[2-i][0];
						rightColor[i][0]=up->getColor()[2][i];
					}else{
						upColor[2][i]=right->getColor()[i][0];
						rightColor[i][0]=down->getColor()[0][2-i];
						downColor[0][i]=left->getColor()[i][2];
						leftColor[i][2]=up->getColor()[2][2-i];
					}
				}
				up->setColor(upColor);
				down->setColor(downColor);
				right->setColor(rightColor);
				left->setColor(leftColor);
			}

			vector<vector<char> > newColor = color;
			if (s=='U'||s=='D'){
				if(s=='U'){
					if(dir=='-')newColor[0]=left->getColor()[0];
					if(dir=='+')newColor[0]=right->getColor()[0];
				} else{
					if(dir=='+')newColor[2]=left->getColor()[2];
					if(dir=='-')newColor[2]=right->getColor()[2];
				}
				if(dir=='+') right->rotate(s,dir,num+1, BF);
				else left->rotate(s,dir,num+1, BF);
					
			}else if(s=='R' || s=='L'){
				vector<vector<char> >copyFrom;
				if(s=='R'){
					if(dir=='-'){
						copyFrom=up->getColor();
						for(int i=0; i<3; i++){
							if(num==1)
								newColor[i][2]=copyFrom[2-i][0];
							else if(num==2)
								newColor[i][0]=copyFrom[2-i][2];
							else
								newColor[i][2]=copyFrom[i][2];
						}
					}
					if(dir=='+'){
						copyFrom=down->getColor();
						for(int i=0; i<3; i++){
							if(num==2)
								newColor[i][0]=copyFrom[2-i][2];
							else if(num==3)
								newColor[i][2]=copyFrom[2-i][0];
							else
								newColor[i][2]=copyFrom[i][2];
						}
					}
				}else{
					if(dir=='+'){
						copyFrom=up->getColor();
						for(int i=0; i<3; i++){
							if(num==1)
								newColor[i][0]=copyFrom[2-i][2];
							else if(num==2)
								newColor[i][2]=copyFrom[2-i][0];
							else
								newColor[i][0]=copyFrom[i][0];
						}
					}
					if(dir=='-'){
						copyFrom=down->getColor();
						for(int i=0; i<3; i++){
							if(num==3)
								newColor[i][0]=copyFrom[2-i][0];
							else if(num==2)
								newColor[i][2]=copyFrom[i][0];
							else
								newColor[i][0]=copyFrom[i][0];
						}
					}
				}
				up->rotate(s, dir,num+1, BF);
			}
			color=newColor;
			if(num!=0) return;
			if(s=='U') up->rotateItself(dir);
			if(s=='D') down->rotateItself(dir);
			if(s=='L') left->rotateItself(dir);
			if(s=='R') right->rotateItself(dir);
			if(s=='F') rotateItself(dir);
			if(s=='B') up->getUp()->rotateItself(dir);
		}
		void rotateItself(char dir){
			vector<vector<char> > newColor=color;
			if(dir=='+'){
				for(int i=0;i <3; i++){
					for(int j=0; j<3; j++){
						newColor[i][j]=color[2-j][i];
					}
				}
			}else{
				for(int i=0; i<3; i++){
					for(int j=0; j<3; j++){
						newColor[i][j]=color[j][2-i];
					}
				}
			}
			color=newColor;
		}
				
};

int main(void){
	int tc;
	cin >> tc;
	vector< vector<vector<char> > > ans;
	for(int i=0; i< tc; i++){
		side* front= new side('r');
		side* up = new side('w');
		side* down = new side('y');
		side* back = new side('o');
		side* left = new side('g');
		side* right = new side('b');

		front->setRight(right);
		right->setLeft(front);
		front->setUp(up);
		up->setDown(front);
		front->setDown(down);
		down->setUp(front);
		front->setLeft(left);
		left->setRight(front);
		back->setUp(down);
		down->setDown(back);
		back->setDown(up);
		up->setUp(back);
		back->setRight(left);
		left->setLeft(back);
		back->setLeft(right);
		right->setRight(back);
		left->setUp(up);
		up->setLeft(left);
		right->setUp(up);
		up->setRight(right);
		
		int numMove;
		cin >> numMove;
		for(int j=0; j<numMove; j++){
			char s, dir;
			cin >> s>>dir;
			cin.get();
			front->rotate(s,dir,0, false);
		}
		ans.push_back(back->getColor());

	}
	for(int t=0; t<tc; t++){
		for(int i=0; i<3;i++){
			for(int j=0; j<3; j++)
				cout << ans[t][i][j];
			cout <<'\n';
		}
	}
}


