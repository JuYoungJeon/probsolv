#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int cnt=0;
void printMap(int n, int m, vector<vector<int> > map){
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

vector<vector<int> > colorOuterAir(int n, int m, vector<vector<int> > map, int y, int x){
	cout << cnt << '\n';
	cnt++;
	map[y][x]=2;
	for (int i=0; i< 4; i++){
		if(y+directions[i][0]>=0 && y+directions[i][0]<n && x+directions[i][1]>=0 && x+directions[i][1]<m)
			if(map[y+directions[i][0]][x+directions[i][1]]==0)
				map= colorOuterAir(n, m, map, y+directions[i][0], x+directions[i][1]);
	}
	return map;
}

bool checkMelt(vector<vector<int> > map, pair<int, int> target, int n, int m){
	int exposure=0;
	for (int i=0; i< 4; i++){
		if(target.first+directions[i][0]>=0 && target.first+directions[i][0]<n && target.second+directions[i][1]>=0 && target.second+directions[i][1]<m)
			if(map[target.first+directions[i][0]][target.second+directions[i][1]]==2) exposure+=1;
	}
	return exposure>=2;
}

int solution(vector<pair<int, int> > roots, int n, int m, vector<vector<int> > map){
	if (roots.empty()) return 0;
	int hours=1;
	vector<vector<int> > newMap = map;
	for(auto iter = roots.begin(); iter != roots.end(); ){
		if(checkMelt(map, *iter, n, m)){
			//pop
			newMap = colorOuterAir(n, m, newMap, (*iter).first, (*iter).second);
			iter= roots.erase(iter);
		}else
			iter++;
	}
	hours+= solution(roots, n, m, newMap);
	return hours;
}

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);

	vector < pair<int, int> > roots;
	vector < vector<int> > map;

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

	map = colorOuterAir(n, m, map, 0, 0);
	cout << solution(roots, n, m, map) ;
}
