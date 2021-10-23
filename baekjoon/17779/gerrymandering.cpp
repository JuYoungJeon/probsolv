#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int pop[21][21];
int city[21][21];

void printMap(int N){
	for(int i=1;i<=N; i++){
		for(int j=1; j<=N; j++){
			cout<< pop[i][j]<<' ';
		}cout <<'\n';
	}cout <<'\n';
	for(int i=1;i<=N; i++){
		for(int j=1;j<=N; j++){
			cout << city[i][j]<<' ';
		}cout <<'\n';
	}cout <<'\n';
}

int check(int N, int y, int x, int d1, int d2){
	int p[6]={0};
	int cnt=0;
	vector<int> r[21];
	while(cnt<=d1||cnt<=d2){
		if(cnt<=d1){
			if(y-cnt>=1&&city[y-cnt][x+cnt]==0) {
				p[5]+=pop[y-cnt][x+cnt];
				r[y-cnt].push_back(x+cnt);
				city[y-cnt][x+cnt]=5;
			}
			if(y+d2-cnt>=1&&city[y+d2-cnt][x+d2+cnt]==0) {
				p[5]+=pop[y+d2-cnt][x+d2+cnt];
				r[y+d2-cnt].push_back(x+d2+cnt);
				city[y+d2-cnt][x+d2+cnt]=5;
			}
		}
		if(cnt<=d2){
			if(y+cnt<=N&&city[y+cnt][x+cnt]==0) {
				p[5]+=pop[y+cnt][x+cnt];
				r[y+cnt].push_back(x+cnt);
				city[y+cnt][x+cnt]=5;
			}
			if(y-d1+cnt>=1&&city[y-d1+cnt][x+d1+cnt]==0){
				p[5]+=pop[y-d1+cnt][x+d1+cnt];
				r[y-d1+cnt].push_back(x+d1+cnt);
				city[y-d1+cnt][x+d1+cnt]=5;
			}
		}
		cnt+=1;
	}
	for(int i=1; i<=N; i++){
		if(r[i].size()<=1) continue;
		for(int j=min(r[i][0], r[i][1])+1; j<max(r[i][0],r[i][1]); j++){
			p[5]+=pop[i][j];
			city[i][j]=5;
		}
	}
	for(int i=1;i<=N; i++){
		for(int j=1; j<=N; j++){
			if(city[i][j]==0&&j>=1&&j<=x+d1&&i>=1&&i<y){
				p[1]+=pop[i][j];
				city[i][j]=1;
			}else if(city[i][j]==0&&j>=1&&j<x+d2&&i>=y&&i<=N){
				p[3]+=pop[i][j];
				city[i][j]=3;
			}else if(city[i][j]==0&&j>x+d1&&j<=N&&i>=1&&i<=y-d1+d2){
				p[2]+=pop[i][j];
				city[i][j]=2;
			}else if(city[i][j]==0&&j>=x+d2&&j<=N&&i>=y-d1+d2&&i<=N){
				p[4]+=pop[i][j];
				city[i][j]=4;
			}
		}
	}

	int maxp=p[1], minp=p[1];
	for(int i=2; i<=5; i++){
		maxp=max(maxp, p[i]);
		minp=min(minp, p[i]);
	}
	return maxp-minp;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int ans=0;
	for(int i=1;i<=N; i++){
		for(int j=1;j<=N; j++){
			cin >> pop[i][j];
			ans+=pop[i][j];
		}
	}
	for(int y=1; y<=N; y++){
		for(int x=1; x<=N; x++){
			for(int d1=1; d1<N; d1++){
				for(int d2=1; d2<N; d2++){
					if(x+d1+d2>N||y-d1<1||y+d2>N) continue;
					memset(city, 0, sizeof(city));
					ans = min(ans, check(N, y, x, d1, d2));
				}
			}
		}
	}
	cout << ans;
}
