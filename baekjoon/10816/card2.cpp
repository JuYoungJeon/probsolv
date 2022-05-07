#include<iostream>
#include<map>

using namespace std;

map<int, int> m;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for(int i=0;i<N; i++){
		int t;
		cin >> t;
		if(m.find(t)!=m.end()) m[t]+=1;
		else m.insert({t, 1});
	}
	int M; 
	cin >> M;
	for(int i=0;i<M; i++){
		int t;
		cin >> t;
		if(m.find(t)!=m.end()) cout << m[t]<<' ';
		else cout << 0<<' ';
	}
}
