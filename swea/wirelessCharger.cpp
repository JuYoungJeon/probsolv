#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
#define pii pair<int, int>

int map[10][10][9];
int dir[5][2]={{0,0},{-1,0},{0,1},{1,0},{0,-1}};
int userA[101][2];
int userB[101][2];
int BC[9];

int main(void){
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int TC;
	cin >> TC;
	for(int test_case=1; test_case<=TC; test_case++){
		memset(map, 0, sizeof(map));
		memset(userA, 0, sizeof(userA));
		memset(userB, 0, sizeof(userB));
		int M, A;
		cin >> M >> A;
		userA[0][0]=0, userA[0][1]=0;
		userB[0][0]=9, userB[0][1]=9;
		for(int i=1; i<=M; i++){
			int d;
			cin >>d;
			userA[i][0]=userA[i-1][0]+dir[d][0];
			userA[i][1]=userA[i-1][1]+dir[d][1];
		}
		for(int i=1; i<=M; i++){
			int d;
			cin >> d;
			userB[i][0]=userB[i-1][0]+dir[d][0];
			userB[i][1]=userB[i-1][1]+dir[d][1];
		}
		for(int i=1; i<=A; i++){
			int x, y, c, p;
			cin >> x>>y>>c>>p;
			queue<pii> q;
			q.push({y-1, x-1});
			BC[i]=p;
			while(!q.empty()){
				int cy=q.front().first;
				int cx=q.front().second;
				q.pop();
				for(int j=1;j<=4; j++){
					int ny = cy+dir[j][0];
					int nx= cx+dir[j][1];
					if(ny<0||nx<0||nx>=10||ny>=10) continue;
					if(abs(ny-(y-1))+abs(nx-(x-1))>c) continue;
					if(map[ny][nx][i]) continue;
					map[ny][nx][i]=p;
					q.push({ny, nx});
				}
			}
		}
		int ans=0;
		for(int i=0;i<=M; i++){
			int maxPA=0, maxPA2=0;
			int maxPB=0, maxPB2=0;
			for(int j=1;j<=A; j++){
				if(BC[maxPA]<map[userA[i][0]][userA[i][1]][j]){
					maxPA2=maxPA;
					maxPA=j;
				}else if(BC[maxPA2]<map[userA[i][0]][userA[i][1]][j]){
					maxPA2=j;
				}
				if(BC[maxPB]<map[userB[i][0]][userB[i][1]][j]){
					maxPB2=maxPB;
					maxPB=j;
				}else if(BC[maxPB2]<map[userB[i][0]][userB[i][1]][j]){
					maxPB2=j;
				}
			}
			if(maxPA!=maxPB) ans+=(BC[maxPA]+BC[maxPB]);
			else if(maxPA2==0&&maxPB2==0) ans+=BC[maxPA];
			else ans+=max(BC[maxPA]+BC[maxPB2], BC[maxPB]+BC[maxPA2]);
		}
		cout <<'#'<<test_case<<' '<< ans<<'\n';
	}
}
