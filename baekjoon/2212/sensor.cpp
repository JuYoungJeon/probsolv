#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int sensors[10000];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	for(int i=0;i<N; i++){
		cin >> sensors[i];
	}
	sort(sensors, sensors+N);
	priority_queue<int, vector<int>, less<>> twoDist;
	for(int i=1; i<N; i++){
		twoDist.push(sensors[i]-sensors[i-1]);
	}
	int answer = sensors[N-1]-sensors[0];
	for(int i=0; i<K-1; i++){
		if(twoDist.empty()) break;
		answer-=twoDist.top();
		twoDist.pop();
	}
	cout << max(answer, 0);
}
