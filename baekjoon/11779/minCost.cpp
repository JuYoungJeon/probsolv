#include<cstdio>
#include<vector>
#include<queue>
#include<climits>
#define INF INT_MAX
using namespace std;
int dist[1001];
int back[1001];

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<pair<int, int> > edges[1001];
	for(int i=0; i<m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges[a].push_back(make_pair(b, c));
	}
	for(int i=1; i<=n; i++) dist[i]=INF;
	for(int i=1; i<=n; i++) back[i]=-1;
	int s, e;
	scanf("%d %d", &s, &e);
	dist[s]=0;
	back[s]=s;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(dist[s], s));
	while(!pq.empty()){
		pair<int, int> c = pq.top();
		pq.pop();
		for(auto &e: edges[c.second]){
			if(dist[e.first]>c.first+e.second) {
				dist[e.first]=c.first+e.second;
				back[e.first]=c.second;
				pq.push(make_pair(dist[e.first], e.first));
			}
		}
	}
	printf("%d\n", dist[e]);
	int b=e;
	int cnt=1;
	vector<int> res; 
	while(b!=back[b]){
		res.push_back(b);
		b=back[b];
		cnt+=1;
	}
	res.push_back(s);
	printf("%d\n", cnt);
	for(int i=res.size()-1; i>=0; i--)
		printf("%d ", res[i]);
}
