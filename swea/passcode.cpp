#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int tc;
	cin >> tc;
	while(tc--){
		priority_queue<string, vector<string>, less<string>> pq;
		vector<string> a;
		int N, K;
		cin >> N >> K;
		string s;
		cin >> s;
		int ns=N/4;
		for(int i=0;i<s.size(); i++){
			string tmp = s.substr(i,s.size()-i)+s.substr(0, i);
			for(int j=0; j<=s.size()-ns; j+=ns){
				pq.push(tmp.substr(j,ns));
			}
		}
		while(!pq.empty()){
			if(a.empty()||a.back()!=pq.top())a.push_back(pq.top());
			pq.pop();
		}
		long long answer=0;
		int idx=pow(16, ns-1);
		for(char c:a[K-1]){
			long long t=1;
			if(c>='A'&&c<='F') t*=idx*(c-'A'+10);
			else t*=idx*(c-'0');
			idx/=16;
			answer+=t;
		}
		cout << answer<<'\n';
	}
}
