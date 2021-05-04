#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
	int tc;
	scanf("%d", &tc);
	for(int i=0; i<tc; i++){
		int n,m;
		queue<pair<int, int> > q;
		vector<int> p;
		scanf("%d %d", &n, &m);
		for(int j=0; j<n; j++){
			int t;
			scanf("%d", &t);
			q.push(make_pair(j,t));
			p.push_back(t);
		}
		sort(p.begin(), p.end(), greater<int>());
		int idx=0;
		int ans=0;
		while(!q.empty()){
			pair<int, int> next=q.front();
			q.pop();
			if(next.second!=p[idx]){
				q.push(next);
			}else{
				idx++;
				if(next.first==m){ printf("%d\n", idx); break;}
			}
		}
	}

}
