#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	int s=1, e=N;
	int a[202], r[202];
	memset(a, 0, sizeof(a));
	memset(r, 0, sizeof(r));
	vector<int> robot;
	int cnt=0;
	int answer=0;
	for(int i=1; i<=2*N; i++){
		cin >> a[i];
		if(!a[i]) cnt+=1;
	}
	while(cnt<K){
		if(s>1) s-=1;
		else s=2*N;
		if(e>1) e-=1;
		else e=2*N;
		r[e]=0;
		vector<int> tmp; 
		for(int i=0; i<robot.size(); i++){
			int rob = robot[i];
			if(rob==e) {r[e]=0;continue;}
			if(rob<2*N&&a[rob+1]&&!r[rob+1]&&r[rob]){
				r[rob+1]=r[rob]; r[rob]=0;
				a[rob+1]--;
				if(!a[rob+1]) cnt+=1;
				if(rob+1==e) r[rob+1]=0; 
				else tmp.push_back(rob+1);
			}else if(rob==2*N&&a[1]&&!r[1]&&r[rob]){
				r[1]=r[rob]; r[rob]=0;
				a[1]--;
				if(!a[1]) cnt+=1;
				if(1==e) r[1]=0; 
				else tmp.push_back(1);
			}else tmp.push_back(rob);
		}
		robot.clear();
		robot = tmp;
		if(a[s]&&!r[s]){ robot.push_back(s); a[s]--; r[s]=1; if(!a[s]) cnt+=1;}

		answer+=1;
	}
	cout << answer<<'\n';
}
