#include<iostream>
#include<bitset>
#include<cmath>

using namespace std;
int honey[10][10];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++){
		int N, M, C;
		cin >> N>>M>>C;
		int ans=0;
		for(int i=0;i<N; i++){
			for(int j=0;j<N; j++){
				cin>> honey[i][j];
			}
		}
		int maxCost=0;
		for(int fy=0;fy<N; fy++){
			for(int fx=0;fx<N; fx++){
				int maxF=0;
				for(int fl=0;fl<(1<<M); fl++){
					int fc=0;
					int fn=0;
					bitset<5> bs(fl);
					for(int f=0; f<M&&fx+f<N; f++){
						if(bs[f]){
							fn+=honey[fy][fx+f];
							fc+=pow(honey[fy][fx+f],2);
						}
					}
					if(fn>C) continue;
					maxF=max(maxF, fc);
				}
				for(int sy=fy; sy<N; sy++){
					int sx;
					if(sy==fy) sx=fx+M;
					else sx=0;
					for(; sx<N; sx++){
						int maxS=0;
						for(int sl=0; sl<(1<<M); sl++){
							int sc=0;
							int sn=0;
							bitset<5> bs(sl);
							for(int s=0; s<M&&sx+s<N; s++){
								if(bs[s]){
									sn+=honey[sy][sx+s];
									sc+=pow(honey[sy][sx+s],2);
								}
							}
							if(sn>C) continue;
							maxS=max(maxS, sc);
						}
						maxCost=max(maxCost, maxF+maxS);
					}
				}
			}
		}
		cout << '#'<<test_case<<' '<<maxCost<<'\n';
	}
}
