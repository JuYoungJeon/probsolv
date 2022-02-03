#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin>>N;

	int ans=N;
	vector<int> friends[51];
	int scores[51];
	memset(scores, 0, sizeof(scores));
	int cnt=0;

	while(1){
		int a, b;
		cin >> a >> b;
		if(a==-1&& b==-1) break;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	for(int i=1;i<=N; i++){
		queue<int> q;
		int dist[50];
		memset(dist, 0, sizeof(dist));
		dist[i]=1;
		q.push(i);
		while(!q.empty()){
			int c = q.front();
			q.pop();
			for(auto n: friends[c]){
				if(dist[n]==0) {
					dist[n]=dist[c]+1;
					q.push(n);
				}
			}
		}
		scores[i]=*max_element(dist, dist+N+1)-1;
		if(ans>scores[i]){
			cnt=1;
			ans=scores[i];
		}else if(ans==scores[i]){
			cnt+=1;
		}
	}
	cout << ans<<' '<<cnt<<'\n';
	for(int i=1; i<=N; i++){
		if(scores[i]==ans) cout << i<<' ';
	}
}
