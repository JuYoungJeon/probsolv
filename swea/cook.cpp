#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int syn[16][16];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int TC; 
	cin >> TC;
	for(int test_case=1; test_case<=TC; test_case++){
		int N;
		cin >> N;
		int ans=0;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin >> syn[i][j];
				ans+=syn[i][j];
			}
		}
		vector<int> comb(N, 0);
		for(int i=N/2;i<N; i++) comb[i]=1;
		do{
			vector<int> a, b;
			int sa=0, sb=0;
			for(int i=0;i<N; i++){
				if(comb[i]) a.push_back(i);
				else b.push_back(i);
			}
			for(int i=0;i<N/2; i++){
				for(int j=0; j<N/2; j++){
					sa+=syn[a[i]][a[j]];
					sb+=syn[b[i]][b[j]];
				}
			}
			ans=min(ans, abs(sa- sb));
		}while(next_permutation(comb.begin(), comb.end()));
		cout << '#'<<test_case<<' '<<ans<<'\n';
	}
}
