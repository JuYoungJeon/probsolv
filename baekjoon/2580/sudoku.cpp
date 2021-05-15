#include<cstdio>
#include<cstring>
#include<deque>
#include<vector>
using namespace std;
int map[9][9];
int vCheck[9][9];
int hCheck[9][9];
int bCheck[9][9];

bool dfs(deque<pair<int, int> > c){
	if(c.empty()) return true;
	bool ret =false;
	pair<int, int> next= c.front();
	c.pop_front();
	for(int i=0; i<9; i++){
		if(!vCheck[next.first][i]&&!hCheck[next.second][i]&&!bCheck[next.first/3*3+next.second/3][i]){
			map[next.first][next.second]=i+1;
			vCheck[next.first][i]=1;
			hCheck[next.second][i]=1;
			bCheck[next.first/3*3+next.second/3][i]=1;
			ret= dfs(c);
			if(ret) break;
			map[next.first][next.second]=0;
            vCheck[next.first][i]=0;
            hCheck[next.second][i]=0;
            bCheck[next.first/3*3+next.second/3][i]=0;
		}
	}
	
	return ret;
}

int main(void){
	memset(vCheck, 0, sizeof(vCheck));
	memset(hCheck, 0, sizeof(hCheck));
	memset(bCheck, 0, sizeof(bCheck));
	deque<pair<int, int> > c;
	for(int i=0;i <9; i++){
		for(int j=0; j<9; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j]){
				vCheck[i][map[i][j]-1]=1;
				hCheck[j][map[i][j]-1]=1;
				bCheck[(i/3*3)+j/3][map[i][j]-1]=1;
			}else{
				c.push_back(make_pair(i, j));
			}
		}
	}
	dfs(c);
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}
