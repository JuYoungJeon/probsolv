#include<iostream>
#include<vector>

using namespace std;

#define pii pair<int,int>

int disk[50][50];
int dir[50];

void printMap(int N, int M){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << disk[i][(dir[i]+j)%M]<<' ';
		}cout <<'\n';
	}
}

int move(int M, int cur, int d, int k){
	if(d==0){
		if(cur-k<0) return cur+M-k;
		else return cur-k;
	}else{
		if(cur+k>=M) return cur+k-M;
		else return cur+k;
	}
}

void erase(int N, int M){
	vector<pii> changed;
	bool ac=false;
	int avg[2]={0};
	for(int i=0;i<N; i++){
		for(int j=0;j<M; j++){
			bool c=false;
			int curj=(dir[i]+j)%M;
			if(disk[i][curj]==0) continue;
			if(i!=0){
				if(disk[i-1][(dir[i-1]+j)%M]==disk[i][curj]){
					c=true;
					changed.push_back({i-1, (dir[i-1]+j)%M});
				}
			}else if(i!=N-1){
				if(disk[i+1][(dir[i+1]+j)%M]==disk[i][curj]){
					c=true;
					changed.push_back({i+1, (dir[i+1]+j)%M});
				}
			}
			if(disk[i][curj]==disk[i][move(M, curj, 0, 1)]){
				c=true;
				changed.push_back({i, move(M, curj, 0, 1)});
			}
			if(disk[i][curj]==disk[i][move(M, curj, 1, 1)]){
				c=true;
				changed.push_back({i, move(M, curj, 1, 1)});
			}
			if(c){
				changed.push_back({i, curj});
				ac=true;
			}
			if(disk[i][curj]){
				avg[0]+=disk[i][curj];
				avg[1]+=1;
			}
		}
	}
	if(!ac){
		for(int i=0;i<N; i++){
			for(int j=0; j<M; j++){
				int curj=(dir[i]+j)%M;
				if(disk[i][curj]==0) continue;
				if(disk[i][curj]>avg[0]*1.0/avg[1]){
					disk[i][curj]-=1;
				}else if(disk[i][curj]<avg[0]*1.0/avg[1]){
					disk[i][curj]+=1;
				}
			}
		}
	}
	for(auto& p: changed){
		disk[p.first][p.second]=0;
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, T;
	cin >> N >> M >> T;
	for(int i=0;i<N; i++){
		for(int j=0;j<M; j++){
			cin >> disk[i][j];
		}
	}
	for(int i=0;i<T; i++){
		int x, d, k;
		cin >>x>>d>>k;
		for(int mul=1; x*mul-1<N; mul++){
			dir[mul*x-1]=move(M, dir[mul*x-1], d, k);
		}
		erase(N, M);
	}
	int ans=0;
	for(int i=0;i<N; i++){
		for(int j=0;j<M; j++){
			ans+=disk[i][j];
		}
	}
	cout << ans<<'\n';
}
