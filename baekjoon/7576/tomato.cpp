#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int tomato[1000][1000]={0};
int numLeft=0;
vector<pair<int, int> > numRipe;
queue <pair<int, int> > q;
vector<int> spreadNum;

void printMap(int m, int n){
	for (int i=0; i< m; i++){
		for(int j=0; j<n; j++){
			cout << tomato[i][j] << ' ';
		}
		cout << '\n';
	}
}

int bfs(int m, int n){
	int days=-1;
	for (int i=0; i< numRipe.size(); i++){
		q.push(numRipe[i]);
	}
	spreadNum.push_back(numRipe.size());
	int iter_tom=0;
	int i=0;
	int numTom=0;
	while(!q.empty()){
		pair<int, int> next = q.front();
		q.pop();
		iter_tom+=1;
		for(int i=0; i< 4; i++){
			int y=next.first+dir[i][0];
			int x=next.second+dir[i][1];
			if(y>=0 && y<m && x>=0 && x<n){
				if (tomato[y][x]==0){
					tomato[y][x]=1;
					numTom+=1;
					numLeft-=1;
					q.push(make_pair(y, x));
				}
			}
		}
		if (iter_tom==spreadNum[i]){
			days+=1;
			i++;
			iter_tom=0;
			if (numTom!=0) {
				spreadNum.push_back(numTom);
				numTom=0;
			}
		}

	}
	if (numLeft!=0) days =-1;
	return days;
}


int main(){
	int m, n;
	cin >> m >> n;

	for (int i=0; i< n; i++){
		for(int j=0; j<m; j++){
			cin >> tomato[i][j];
			if(tomato[i][j]==1){
				numRipe.push_back(make_pair(i, j));
			}
			if(tomato[i][j]==0){
				numLeft+=1;
			}
		}
	}

	cout << bfs(n, m);
}

