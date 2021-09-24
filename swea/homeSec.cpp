#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int map[150][150];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++){
		int N, M;
		cin >> N >> M;
		memset(map, 0, sizeof(map));
		for(int i=0; i<N; i++){
			for(int j=0;j<N; j++){
				cin >> map[i][j];
			}
		}
		int max_val=0;
		int size=1;
		for(int i=0; i<N; i++){
			int kmax=0;
			for(int j=0;j<N; j++){
				for(int k=1; k<=N+2; k++){
					int cost = k*k+(k-1)*(k-1);
					int cnt=0;
					for(int ki=0; ki<N; ki++){
						for(int kj=0;kj<N; kj++){
							if(abs(i-ki)+abs(j-kj)>k-1) continue;
							if(map[ki][kj]) cnt+=1;
						}
					}
					if(cost>cnt*M) continue;
					kmax=max(kmax, cnt);
				}
			}
			max_val=max(kmax, max_val);
		}
		cout <<'#'<<test_case<<' '<< max_val<<'\n';
	}
}
