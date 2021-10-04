#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int map[20][20];
int tar[20];
bool isBlock[20];

int check(int N, int X){
	bool succ=true;
	memset(isBlock, 0, sizeof(isBlock));
	for(int i=0;i<N-1; i++){
		if(tar[i]==tar[i+1]) continue;
		if(abs(tar[i+1]-tar[i])>1) return false;
		if(tar[i]+1==tar[i+1]){
			if(isBlock[i]) return false;
			if(i-X+1<0) return false;
			for(int j=1;j<X; j++){
				if(tar[i-j]!=tar[i]||isBlock[i-j]) return false;
				isBlock[i-j]=1;
			}
		}
		if(tar[i]==tar[i+1]+1){
			if(isBlock[i+1]) return false;
			if(i+X>=N) return false;
			for(int j=1; j<X; j++){
				if(tar[i+1+j]!=tar[i+1]||isBlock[i+1+j]) return false;
				isBlock[i+1+j]=1;
			}
		}
	}
	return succ;
}

void printMap(int N){
	for(int i=0; i<N; i++){
		cout << tar[i]<<' ';
	}cout <<'\n';
}
int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++){
		int N, X;
		cin >> N>>X;
		for(int i=0;i<N; i++){
			for(int j=0; j<N; j++){
				cin >> map[i][j];
			}
		}
		int ans=0;
		for(int i=0;i<N; i++){
			for(int j=0;j<N; j++){
				tar[j]=map[i][j];
			}
			if(check(N, X)) {
				ans+=1;
			}
		}
		for(int j=0;j<N; j++){
			for(int i=0;i<N; i++){
				tar[i]=map[i][j];
			}
			if(check(N, X)) {ans+=1; }
		}
		cout << '#'<<test_case<<' '<<ans<<'\n';
	}
}
