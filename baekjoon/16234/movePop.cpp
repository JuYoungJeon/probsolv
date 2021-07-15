#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int visited[50][50];
int popul[50][50];
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
queue<pair<int, int> > uni;

void printMap(int n){
	for(int i=0;i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", popul[i][j]);
		}
		printf("\n");
	}
}

int bfs(int n, int l, int r, int y, int x){
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	uni.push(make_pair(y, x));
	visited[y][x]=1;
	int sum=0;
	int cnt=0;
	while(!q.empty()){
		pair<int, int> next=q.front();
		q.pop();
		sum+=popul[next.first][next.second];
		cnt+=1;
		for(int i=0;i<4; i++){
			int dy= next.first+dir[i][0]; 
			int dx= next.second+dir[i][1];
			if(dy>=n||dy<0||dx>=n||dx<0) continue;
			int diff = abs(popul[dy][dx]-popul[next.first][next.second]);
			if(diff<l||diff>r) continue;
			if(visited[dy][dx]) continue;
			visited[dy][dx]=1;
			uni.push(make_pair(dy, dx));
			q.push(make_pair(dy, dx));
		}
	}
	return sum/cnt;
}

int main(void){
	int n, l, r;
	scanf("%d %d %d", &n, &l, &r);
	for(int i=0;i <n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &popul[i][j]);
		}
	}
	int days=0; 
	int changed=false;
	do{
		changed=false;
		memset(visited, 0, sizeof(visited));
		for(int i=0;i <n; i++){
			for(int j=0;j<n; j++){
				if(visited[i][j]) continue;
				int newNum = bfs(n, l, r, i, j);
				if(uni.size()>1) changed=true;
				while(changed&&!uni.empty()){
					pair<int, int> next=uni.front();
					uni.pop();
					popul[next.first][next.second]=newNum;
				}
				while(!changed&&!uni.empty()) uni.pop();
			}
		}
		if(changed) days+=1;
	}while(changed);
	printf("%d", days);
}
