#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int dir[8][2]={{-1, -1},{-1,0},{-1,1},{0, -1},{0, 1},{1,-1},{1,0},{1,1}};
int A[10][10];
vector<int> T[10][10];
int E[10][10];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, M, K;
	cin >> N >> M>>K;
	for(int i=0;i<N; i++){
		for(int j=0; j<N; j++) {
			cin >> A[i][j];
			E[i][j]=5;
		}
	}
	for(int i=0;i<M; i++){
		int x, y, z;
		cin >> y>> x>> z;
		T[y-1][x-1].push_back(z);
	}
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			if(T[i][j].size()>1) sort(T[i][j].begin(), T[i][j].end(), greater<int>());
		}
	}
	for(int y =0;y<K; y++){
		int D[10][10];
		memset(D, 0, sizeof(D));
		//spring
		for(int i=0;i<N; i++){
			for(int j=0;j<N; j++){
				int s=-1;
				for(int t=T[i][j].size()-1; t>=0; t--){
					if(T[i][j][t]<=E[i][j]){
						E[i][j]-=T[i][j][t];
						T[i][j][t]+=1;
					}else{
						if(s==-1) s=t;
						D[i][j]+=T[i][j][t]/2;
					}
				}
				if(s!=-1)
					T[i][j].erase(T[i][j].begin(), T[i][j].begin()+s+1);

			}
		}
		//summer, fall, winter
		for(int i=0;i<N; i++){
			for(int j=0;j<N; j++){
				E[i][j]+=D[i][j];
				for(auto& t:T[i][j]){
					if(t%5==0){
						for(int d=0;d<8; d++){
							int y=i+dir[d][0];
							int x=j+dir[d][1];
							if(y<0||x<0||y>=N||x>=N) continue;
							T[y][x].push_back(1);
						}
					}
				}
				E[i][j]+=A[i][j];
			}
		}
	}
	int ans=0;
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			ans+=T[i][j].size();
		}
	}
	cout << ans;
}
