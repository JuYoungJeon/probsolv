#include<iostream>
#include<cstring>
#include<string>
#include<queue>

using namespace std;

string bfs(int A, int B){
	queue<pair<int, string>> q;
	int visited[10001];
	memset(visited, 0, sizeof(visited));
	q.push({A,""});
	while(!q.empty()){
		int cIdx = q.front().first;
		string cstr = q.front().second;
		if(cIdx==B) return cstr;
		q.pop();
		int d = (cIdx*2)%10000;
		int s = (cIdx-1)<0? 9999: cIdx-1;
		int l = (cIdx*10)%10000+(cIdx/1000);
		int r = cIdx/10+(cIdx%10)*1000;
		if(!visited[d]){
			visited[d]=1;
			q.push({d, cstr+"D"});
		}
		if(!visited[s]){
			visited[s]=1;
			q.push({s, cstr+"S"});
		}
		if(!visited[l]){
			visited[l]=1;
			q.push({l, cstr+"L"});
		}
		if(!visited[r]){
			visited[r]=1;
			q.push({r, cstr+"R"});
		}
	}
	return "";
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--){
		int A, B;
		cin >> A>> B;
		cout << bfs(A, B)<<'\n';
	}
}
