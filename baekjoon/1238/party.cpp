#include<cstdio>
#include<vector>
#include<queue>
#include<climits>

#define INF INT_MAX
using namespace std;
int distGo[1001];
int distCome[1001];
vector<pair<int, int> > edges[1001];
vector<pair<int, int> > edgesR[1001];
int main(void){
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);
	for(int i=0; i<m ;i++){
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		edges[a].push_back(make_pair(b, t));
		edgesR[b].push_back(make_pair(a, t));
	}
	for(int i=1; i<=n; i++){
		if(i==x) {distGo[i]=0; distCome[i]=0;}
		else {distGo[i]=INF; distCome[i]=INF;}
	}
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int next=q.front();
		q.pop();
		for(auto &e: edges[next]){
			if(distGo[e.first]>distGo[next]+e.second){
				distGo[e.first]=distGo[next]+e.second;
				q.push(e.first);
			}
		}
	}
	q.push(x);
	while(!q.empty()){
		int next=q.front();
		q.pop();
		for(auto &e: edgesR[next]){
			if(distCome[e.first]>distCome[next]+e.second){
				distCome[e.first]=distCome[next]+e.second;
				q.push(e.first);
			}
		}
	}
	int maxDist=0;
	for(int i=1; i<=n; i++){
		if(distGo[i]+distCome[i]>maxDist) maxDist=distGo[i]+distCome[i];
	}
	printf("%d", maxDist);
}

