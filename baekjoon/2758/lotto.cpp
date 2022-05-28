#include<iostream>
#include<cstring>

using namespace std;

long long lotto[2001][11];

long long getNumLotto(int N, int m){
	if(lotto[m][N]!=-1) return lotto[m][N];
	if(N==1) return lotto[m][N]=m;
	return lotto[m][N]=getNumLotto(N, m-1)+getNumLotto(N-1, m/2);
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(lotto, -1, sizeof(lotto));
	for(int i=0;i<2001; i++) {
		lotto[i][0]=0;
	}
	for(int i=0;i<11; i++){
		lotto[0][i]=0;
	}
	int TC;
	cin >> TC;
	while(TC--){
		int N, m;
		cin >> N >> m;
		cout << getNumLotto(N, m)<<'\n';
	}
}
