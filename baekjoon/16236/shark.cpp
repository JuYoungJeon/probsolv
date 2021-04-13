#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[20][20];
int checkmap[20][20]={0};
int shark_size=2;
int num_eat=0;
queue<pair<int, int> > q;
//up, left, right, down
int dir[4][2]={{-1,0}, {0, -1}, {0, 1}, {1,0}};

void printMap(int n){
	cout << "checkmap\n";
	for(int i=0; i<n; i++){
		for(int j=0;j<n;j++)
			cout << checkmap[i][j] << ' ';
		cout << '\n';
	}
	cout<< "map\n";
	for (int i=0;i <n;i++){
		for(int j=0; j<n; j++)
			cout << map[i][j] <<' ';
		cout <<'\n';
	}
}

int solution(int n, pair<int, int> shark, int leftFish){
    int num_sec=0;
    q.push(shark);
    checkmap[shark.first][shark.second]=1;
	pair<int, int> prev =make_pair(-1,-1) ;
	int minLen=n*n;
    while(!q.empty()){
        if(leftFish==0) break;
        pair<int, int> curr_loc = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int y = curr_loc.first+dir[i][0];
            int x = curr_loc.second+dir[i][1];
			if(y>=n|| y<0 || x>=n || x<0) continue;
            if(!checkmap[y][x] && map[y][x]<=shark_size){
				checkmap[y][x]=checkmap[curr_loc.first][curr_loc.second]+1;
                if(map[y][x]>0 && map[y][x]<shark_size){
					if(minLen>=checkmap[y][x]){
						minLen=checkmap[y][x];
						if(prev.first==-1 || prev.first>y){
							prev=make_pair(y,x);
						}else if(prev.first==-1 ||( prev.first==y &&prev.second>x)){
							prev=make_pair(y,x);
						}
					}
            	}
            	q.push(make_pair(y, x));
			}
        }
		if(prev.first!=-1 &&q.empty()){
			num_sec+=checkmap[prev.first][prev.second]-1;
        	leftFish-=1;
        	num_eat+=1;
			map[prev.first][prev.second]=0;
        	if(num_eat==shark_size){
        		shark_size+=1;
        		num_eat=0;
        	}
			//while(!q.empty()) q.pop();
			q.push(make_pair(prev.first,prev.second));
     		memset(checkmap, 0, sizeof(checkmap));
			checkmap[prev.first][prev.second]=1;
			prev=make_pair(-1,-1);
			minLen=n*n;
		}
    }
	return num_sec;
}

int main(){
    int n;
    cin>>n;
    int leftFish=0;
    pair<int, int> shark;
    for (int i=0; i< n; i++){
        for(int j=0; j<n;j++){
            cin >> map[i][j];
            if(map[i][j]==9){
                shark=make_pair(i,j);
				map[i][j]=0;
			}
            else if(map[i][j]!=0){
                leftFish+=1;
            }
        }
    }
    cout << solution(n, shark, leftFish);
}
