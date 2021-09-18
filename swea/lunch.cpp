#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cmath>
#include<bitset>

using namespace std;

#define pii pair<int,int>

int map[10][10];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; 
	cin >> T;
	for(int test_case=0; test_case<T; test_case++){
		int N;
		cin >> N;
		vector<pii> ps;
		vector<pii> st;
		int dist[10][2];
		memset(map, 0, sizeof(map));
		memset(dist, 0, sizeof(dist));
		for(int i=0;i<N; i++){
			for(int j=0;j<N; j++){
				cin >> map[i][j];
				if(map[i][j]==1) ps.push_back({i, j});
				else if(map[i][j]>1) st.push_back({i, j});
			}
		}
		for(int p=0;p<ps.size(); p++){
			for(int s=0;s<st.size(); s++){
				dist[p][s]=(abs(ps[p].first-st[s].first)+abs(ps[p].second-st[s].second));
			}
		}
		int mintime = 100*10*10;
		int allp = 1<<(N+1);
		for(int p=0; p<allp; p++){
			bitset<10> bp=bitset<10>(p);
			priority_queue<int,vector<int>, greater<int>>pq1, pq2;
			for(int i=0; i<ps.size(); i++){
				if(bp[i])pq1.push(dist[i][0]);
				else pq2.push(dist[i][1]);
			}
			int time1=0, time2=0;
			queue<int> q1, q2;
			while(!pq1.empty()){
				int d=pq1.top();
				pq1.pop();
				if(q1.size()==3){
					if(q1.front()+map[st[0].first][st[0].second]<=d+1){
						q1.push(d+1);
					}else{
						q1.push(q1.front()+map[st[0].first][st[0].second]);
					}
					q1.pop();
				}else q1.push(d+1);
			}
			while(!q1.empty()) {
				time1=q1.front()+map[st[0].first][st[0].second];
				q1.pop();
			}
			while(!pq2.empty()){
				int d=pq2.top();
				pq2.pop();
				if(q2.size()==3){
					if(q2.front()+map[st[1].first][st[1].second]<=d+1){
						q2.push(d+1);
					}else{
						q2.push(q2.front()+map[st[1].first][st[1].second]);
					}
					q2.pop();
				}else q2.push(d+1);
			}
			while(!q2.empty()) {
				time2=q2.front()+map[st[1].first][st[1].second];
				q2.pop();
			}
			mintime = min(mintime, max(time1, time2));
		}
		cout << '#'<<test_case<<' '<<mintime<<'\n';
	}
}
