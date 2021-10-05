#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int mag[4][8];
int ord[20][2];
int p[4];

void rmove(int midx, int mdir){
	int r=(p[midx]+2)%8;
	if(midx<3){
		int rm = (p[midx+1]-2);
		if(rm<0) rm+=8;
		if(mag[midx][r]!=mag[midx+1][rm]){
			rmove(midx+1, mdir*-1);
			p[midx+1]+=mdir;
			if(p[midx+1]<0) p[midx+1]=7;
			else if(p[midx+1]>7) p[midx+1]=0;
		}
	}
}
void lmove(int midx, int mdir){
	int l=(p[midx]-2);
	if(l<0)l=8+l;
	if(midx>0){
		int lm = (p[midx-1]+2)%8;
		if(mag[midx][l]!=mag[midx-1][lm]){
			lmove(midx-1, mdir*-1);
			p[midx-1]+=mdir;
			if(p[midx-1]<0) p[midx-1]=7;
			else if(p[midx-1]>7) p[midx-1]=0;
		}
	}
}
void move(int midx, int mdir){
	rmove(midx, mdir);
	lmove(midx, mdir);
	p[midx]+=(mdir*-1);
	if(p[midx]<0) p[midx]=7;
	else if(p[midx]>7) p[midx]=0;

}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++){
		memset(p, 0, sizeof(p));
		int K;
		cin >> K;
		for(int i=0;i<4; i++){
			for(int j=0; j<8; j++){
				cin >> mag[i][j];
			}
		}
		for(int i=0;i<K; i++){
			cin >> ord[i][0] >> ord[i][1];  
			ord[i][0]-=1;
		}
		for(int i=0; i<K ;i++){
			move(ord[i][0], ord[i][1]);
		}
		int ans=0;
		for(int i=0;i<4; i++){
			if(mag[i][p[i]]) ans+=(pow(2, i));
		}
		cout << '#'<<test_case<<' '<<ans<<'\n';
	}
}
