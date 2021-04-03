#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int board[25][25]={0};
int visited[25][25]={0};
vector<int> numComp;
int compIdx=2;

string dir_s[4]={"up", "down", "right", "left"};
int dir[4][2]={{-1,0},{1,0}, {0,1}, {0, -1}};

int solution(int n, int startY, int startX, int y, int x){
	if (visited[y][x]==1 ) return 0;
	visited[y][x]=1; 
	int ans=0;
	if (board[y][x]==0) return 0;
	board[y][x]=compIdx;
	numComp[compIdx-2]+=1;
	for(int i=0; i<4; i++){
		if (y+dir[i][0] >=0 && y+dir[i][0] < n && x+dir[i][1]>=0 &&x+dir[i][1] < n)
			ans+=solution(n, startY, startX, y+dir[i][0], x+dir[i][1]);
	}
	if(y==startY && x==startX) {
		compIdx+=1;
		numComp.push_back(0);
		ans+=1;
	}
	return ans;
}

int main(){
	int n;

	cin >> n;
	for(int i=0; i < n; i++){
		for (int j=0; j< n; j++){
			char t;
			cin >> t;
			board[i][j]=t-'0';
		}
	}

	int numComplex=0;
	numComp.push_back(0);
	for (int i=0; i<25; i++){
		for(int j=0; j<25; j++){
			numComplex+=solution(n, i, j, i, j);
		}
	}
	cout << numComplex<< '\n';
	sort(numComp.begin(), numComp.end()-1);
	for (int i=0; i< numComplex; i++)
		cout << numComp[i] << '\n';
}
