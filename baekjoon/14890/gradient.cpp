#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct block{
	int y;
	int x;
	int h;
	bool canput;
};

vector<vector< block > > mapRow;
vector<vector< block > > mapCol;

int arr[100][100]={0};

int solution(int n, int l){
	int ans=0;
	//가로
	for(int i=0;i<n; i++){
		bool succ=true;
		bool leftLow=true;
		for(int j=0;j<mapRow[i].size()-1; j++){
			leftLow=true;
			if(abs(mapRow[i][j+1].h - mapRow[i][j].h) > 1){
				succ=false;
				break;
			}
			if(mapRow[i][j+1].h < mapRow[i][j].h){
				leftLow=false;
			}
			if(leftLow){
				if (!mapRow[i][j].canput){
					succ=false;
					break;
				}
				if(mapRow[i][j+1].x - mapRow[i][j].x < l ){
					succ=false;
					break;
				}
			}else{
				if(!mapRow[i][j+1].canput){
					succ=false;
					break;
				}
				if(j+2<mapRow[i].size()){
					int len = mapRow[i][j+2].x-mapRow[i][j+1].x;
					if(len<l){
						succ=false;
						break;
					}
					if(len>=l){
						mapRow[i][j+1].x=mapRow[i][j+1].x+l;
						if (mapRow[i][j+1].x==mapRow[i][j+2].x)
							mapRow[i][j+1].canput=false;
						continue;
					}
				}
				else if(n-mapRow[i][j+1].x<l){
					succ=false;
					break;
				}

			}
		}
		if(succ) ans+=1;
		succ=true;
		for(int j=0; j<mapCol[i].size()-1; j++){
			leftLow=true;
			if(abs(mapCol[i][j+1].h - mapCol[i][j].h) >1){
				succ=false;
				break;
			}
			if(mapCol[i][j+1].h < mapCol[i][j].h) leftLow=false;
			if(leftLow){
				if (!mapCol[i][j].canput){
					succ=false;
					break;
				}
				if((mapCol[i][j+1].y-mapCol[i][j].y)<l){
					succ=false;
					break;
				}
			}else{
				if(!mapCol[i][j+1].canput){
					succ=false;
					break;
				}
				if(j+2<mapCol[i].size()){
					int len=mapCol[i][j+2].y - mapCol[i][j+1].y;

					if(len<l){
						succ=false;
						break;
					}
					if(len>=l){
						mapCol[i][j+1].y=mapCol[i][j+1].y+l;
						if(mapCol[i][j+1].y==mapCol[i][j+2].y) mapCol[i][j].canput=false;
						continue;
					}
				}else if (n-mapCol[i][j+1].y < l ){
					succ =false;
					break;
				}
			}
		}
		if (succ) ans+=1;
	}
	return ans;
}

int main(void){
	int n, l;
	cin >> n >> l;
	for(int i=0; i<n;i++){
		int prevHR=0;
		vector<block> row;
		for(int j=0; j<n; j++){
			int h;
			cin >> h;
			arr[i][j]=h;
			if(prevHR!=h){
				block newBlock={i,j,h, true};
				prevHR=h;
				row.push_back(newBlock);
			}
		}
		mapRow.push_back(row);
	}
	for(int j=0; j<n; j++){
		int prevHC=0;
		vector<block> col;
		for(int i=0; i<n; i++){
			int h=arr[i][j];
			if(prevHC!=h){
				block newBlock={i,j,h, true};
				prevHC=h;
				col.push_back(newBlock);
			}
		}
		mapCol.push_back(col);
	}
	cout << solution(n, l);
}
