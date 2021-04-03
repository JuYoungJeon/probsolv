#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int map[50][50]={0};
int visited[50][50]={0};
queue<pair<int,int> >q; 
// down, up, right, left, up-left, up-right, down-left, down-right
int dir[8][2]={{1,0},{-1,0},{0, 1},{0, -1}, {-1,-1}, {-1, 1}, {1, -1}, {1, 1}};

int solution(int w, int h, int y, int x){
	if (visited[y][x]==1) return 0;
	visited[y][x]=1;
	if (map[y][x]==0) return 0;
	q.push(make_pair(y, x));
	while(!q.empty()){
		pair<int,int> next = q.front();
		q.pop();
		for (int i=0; i< 8; i++){
			int next_y = next.first+dir[i][0];
			int next_x = next.second+dir[i][1];
			if(next_y >=0 && next_y <h && next_x >=0 && next_x < w){
				if(visited[next_y][next_x]==0&& map[next_y][next_x]==1){
					visited[next_y][next_x]=1;
					q.push(make_pair(next_y, next_x));
				}
			}
		}
	}
	return 1;
}

int main(){

	vector <int> ans;

	while(1){
		int w, h;
		cin >> w >> h;
		
		if (w==0 && h==0) break;
		for (int i=0; i< h; i++){
			for (int j=0; j<w; j++){
				cin >> map[i][j]; 
			}
		}
		int sol=0;
		for (int i=0;i< h; i++){
			for (int j=0; j<w; j++){
				sol+=solution(w, h, i, j);
			}
		}
		ans.push_back(sol);
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}
	for (int i=0; i< ans.size(); i++)
		cout << ans[i] << '\n';

}
