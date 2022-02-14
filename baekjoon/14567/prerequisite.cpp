#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int innode[1001];
int sem[1001];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> post[1001];
	for(int i=0;i<M; i++){
		int A, B;
		cin >> A >> B;
		innode[B]+=1;
		post[A].push_back(B);
	}
	queue<int> q;
	for(int i=1; i<=N; i++){
		if(innode[i]==0) {
			q.push(i);
			sem[i]=1;
		}
	}
	while(!q.empty()){
		int c = q.front();
		q.pop();
		for(auto n: post[c]){
			innode[n]-=1;
			if(innode[n]==0){
				sem[n]=sem[c]+1;
				q.push(n);
			}
		}
	}
	for(int i=1; i<=N; i++){
		cout << sem[i] <<' ';
	}
}
