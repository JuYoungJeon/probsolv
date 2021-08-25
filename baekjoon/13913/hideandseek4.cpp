#include<cstdio>
#include<vector>
#include<queue> 

using namespace std;

int map[200002];

int bfs(int curr, int k){
	queue<int> q;
	q.push(curr);
	while(!q.empty()){
		int next = q.front();
		q.pop();
		if(next==k) break;
		for(int i=0; i<3; i++){
			int nx;
			if(i==0) nx=next+1;
			if(i==1) nx=next-1;
			if(i==2) nx=next*2;
			if(nx>200000||nx<0) continue;
			if(map[nx]!=0&&map[nx]<=map[next]+1) continue;
			map[nx]=map[next]+1;
			q.push(nx);
		}
	}
	map[curr]=0;
	return map[k];
}

int main(void){
	int n, k;
	scanf("%d %d", &n, &k);
	int ans = bfs(n, k);
	printf("%d\n", ans);
	int curr =k;
	vector<int> q;
	q.push_back(curr);
	while(curr!=n){
		if(curr-1>=0&&map[curr-1]==map[curr]-1) {
			q.push_back(curr-1);
			curr=curr-1;
			continue;
		}
		if(curr+1<200001&&map[curr+1]==map[curr]-1){
			q.push_back(curr+1);
			curr+=1;
			continue;
		}
		if(curr%2==0&&map[curr/2]==map[curr]-1){
			q.push_back(curr/2);
			curr/=2;
		}
	}
	for(int i=q.size()-1; i>=0; i--)
		printf("%d ", q[i]);
}
