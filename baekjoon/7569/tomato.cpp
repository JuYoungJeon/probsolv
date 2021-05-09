#include<cstdio>
#include<tuple>
#include<queue>
using namespace std;
int days[101][101][101];
int tomatos[101][101][101];
queue<tuple<int, int, int> > q;
int dir[6][3]={{-1,0,0},{1,0,0},{0, 1, 0},{0, -1, 0},{0,0,-1},{0,0,1}};

int bfs(int h, int n, int m, int numZero){
	int maxD=1;
	while(!q.empty()){
		tuple<int,int,int> next=q.front();
		q.pop();
		int date=days[get<0>(next)][get<1>(next)][get<2>(next)];
		maxD=max(maxD, date);
		for(int i=0;i<6; i++){
			int nz=get<0>(next)+dir[i][0];
			int ny=get<1>(next)+dir[i][1];
			int nx=get<2>(next)+dir[i][2];

			if(nz>=0&&nz<h&&ny>=0&&ny<n&&nx>=0&&nx<m){
				if(days[nz][ny][nx]!=0) continue;
				if(tomatos[nz][ny][nx]!=0) continue;
				q.push(make_tuple(nz, ny, nx));
				days[nz][ny][nx]=date+1;
				tomatos[nz][ny][nx]=1;
				numZero-=1;
			}
		}
	}
	if(numZero!=0) return -1;
	else return maxD-1;
}

int main(void){
	int m, n, h;
	scanf("%d %d %d", &m, &n, &h);
	int emptyBlock=0, numZero=0;
	for(int i=0; i<h; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				scanf("%d", &tomatos[i][j][k]);
				if(tomatos[i][j][k]==1){
					q.push(make_tuple(i, j, k));
					days[i][j][k]=1;
				}else if(tomatos[i][j][k]==-1) emptyBlock+=1;
				else numZero+=1;
			}
		}
	}
	//if(q.size()==h*n*m-emptyBlock) printf("0");
	//else{
		int ans=bfs(h, n, m, numZero);
		printf("%d", ans);
	//}
}
//NOTE: Tuple 활용하기 acess는 get<0>(tup) 이렇게, 만드는 것은 make_tuple();
