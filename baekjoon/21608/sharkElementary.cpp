#include<iostream>
#include<vector>

using namespace std;

struct seatInfo{
	int y, x, nf, ne;
};

const int dir[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int classroom[20][20];
int friends[405][4];
int order[400];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int ans=0;
	for(int i=0;i<N*N; i++){
		cin >> order[i];
		for(int j=0;j<4; j++){
			cin >> friends[order[i]][j];
		}
	}
	for(int i=0;i<N*N; i++){
		seatInfo tar={-1, -1, -1, -1};
		for(int cy = 0; cy<N; cy++){
			for(int cx=0; cx<N; cx++){
				if(classroom[cy][cx]!=0) continue;
				int emp =0;
				int fri =0;
				for(int d=0;d<4; d++){
					int ny = cy + dir[d][0];
					int nx = cx + dir[d][1];
					if(ny<0||nx<0||ny>=N||nx>=N) continue;
					if(!classroom[ny][nx]) {emp+=1; continue;}
					for(int f=0;f<4; f++){
						if(classroom[ny][nx]==friends[order[i]][f]) {fri+=1; continue;}
					}
				}
				if((tar.y==-1&&tar.x==-1)||(tar.nf<fri)||(tar.nf==fri&&tar.ne<emp)){
					tar.y=cy;
					tar.x=cx;
					tar.ne=emp;
					tar.nf=fri;
				}
			}
		}
		classroom[tar.y][tar.x]=order[i];
	}
	for(int i=0;i<N; i++){
		for(int j=0;j<N; j++){
			int cnt=0;
			for(int d=0; d<4; d++){
				int ny= i+dir[d][0];
				int nx =j+dir[d][1];
				if(ny<0||nx<0||ny>=N||nx>=N) continue;
				for(int f=0;f<4; f++){
					if(classroom[ny][nx]==friends[classroom[i][j]][f]) {cnt+=1; continue;}
				}
			}
			if(cnt==1) ans+=1;
			if(cnt==2) ans+=10;
			if(cnt==3) ans+=100;
			if(cnt==4) ans+=1000;
		}
	}
	cout << ans;
}
