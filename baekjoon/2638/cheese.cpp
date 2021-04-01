#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int cnt=0;
vector<pair<int, int> > roots;
vector<vector<int> > map; 
vector<vector<int> > newMap;
void printMap(int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

//up, down, right, left
string dir[4]={"up", "right", "down", "left"};
int directions[4][2] ={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void colorOuterAir(int n, int m, int y, int x){
	map[y][x]=2;
	for (int i=0; i< 4; i++){
		if(y+directions[i][0]>=0 && y+directions[i][0]<n && x+directions[i][1]>=0 && x+directions[i][1]<m)
			if(map[y+directions[i][0]][x+directions[i][1]]==0)
				colorOuterAir(n, m, y+directions[i][0], x+directions[i][1]);
	}
}

bool checkMelt(pair<int, int> target, int n, int m){
	int exposure=0;
	for (int i=0; i< 4; i++){
		if(target.first+directions[i][0]>=0 && target.first+directions[i][0]<n && target.second+directions[i][1]>=0 && target.second+directions[i][1]<m)
			if(newMap[target.first+directions[i][0]][target.second+directions[i][1]]==2) exposure+=1;
	}
	return exposure>=2;
}

int solution(int n, int m){
	if (roots.empty()) return 0;
	int hours=1;

	newMap=map;
	for(auto iter = roots.begin(); iter != roots.end(); ){
		if(checkMelt(*iter, n, m)){
			//pop
			colorOuterAir(n, m, (*iter).first, (*iter).second);
			iter= roots.erase(iter);
		}else
			iter++;
	}
	hours+= solution(n, m);
	return hours;
}

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i=0; i<n; i++){
		vector<int> tmp;
		for (int j=0; j<m; j++){
			int t;
			scanf("%d", &t);
			tmp.push_back(t);
			if(t==1){
				roots.push_back(make_pair(i,j));
			}
		}
		map.push_back(tmp);
	}

	newMap=map;
	colorOuterAir(n, m, 0, 0);
	cout << solution(n, m) ;
}
