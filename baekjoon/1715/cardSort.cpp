#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int arr[100000];
	cin >> N;
	long long ans =0;
	priority_queue<int, vector<int>, greater<int>> pq;
	sort(arr, arr+N);
	for(int i=0;i<N; i++){
		cin >> arr[i];
		pq.push(arr[i]);
	}
	int h=0;
	while(!pq.empty()){
		if(h==0){
			h=pq.top();
		}else{
			ans+=h+pq.top();
			if(pq.size()!=1) pq.push(h+pq.top());
			h=0;
		}
		pq.pop();
	}
	cout << ans;
}
