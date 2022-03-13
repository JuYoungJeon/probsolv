#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int N, M, D;
int arr[15][15];
int visited[15][15];

int getKilledNum(vector<int> arch){
	int ret =0;
	int tmp[15][15];
	for(int i=0;i<N; i++){
		for(int j=0;j<M;j++){
			tmp[i][j]=arr[i][j];
		}
	}
	for(int i=N-1;i>=0; i--){
		for(int al: arch){
			bool found=false;
			for(int j=0;j<D; j++){
				for(int k=al-j; k<=al+j; k++){
					if(k<0||k>=M) continue;
					if(j<abs(k-al)) continue;
					if(i-(j-abs(k-al))>=0&&tmp[i-(j-abs(k-al))][k]){
						found=true;
						visited[i-(j-abs(k-al))][k]=1;
						break;
					}
				}
				if(found) break;
			}
		}
		for(int i=0;i<N; i++){
			for(int j=0;j<M; j++){
				if(visited[i][j]){
					tmp[i][j]=0;
					ret++;
					visited[i][j]=0;
				}
			}
		}
	}
	return ret; 
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans=0;
	cin >> N >> M>> D;
	for(int i=0;i<N; i++){
		for (int j=0;j<M; j++){
			cin >> arr[i][j];
		}
	}
	vector<int> tmp(M,0);
	for(int i=0; i<3; i++) tmp[i]=1;
	do{
		vector<int> arch;
		memset(visited, 0, sizeof(visited));
		for(int i=0; i<M; i++){
			if(tmp[i]) arch.push_back(i);
		}
		ans = max(ans, getKilledNum(arch));
	}while(prev_permutation(tmp.begin(), tmp.end()));
	cout << ans;
}
