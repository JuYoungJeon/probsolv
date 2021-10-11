#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
#define pii pair<int, int>

int A[1000001];
int f[1000001];
int ans[1000001];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;

	for(int i=0;i<N; i++){
		cin>> A[i];
		f[A[i]]++;
	}
	stack<pii> st;
	for(int i=0; i<N; i++){
		while(!st.empty()&&st.top().first<f[A[i]]){
			ans[st.top().second]=A[i];
			st.pop();
		}
		st.push({f[A[i]], i});
	}
	while(!st.empty()) {
		ans[st.top().second]=-1;
		st.pop();
	}
	for(int i=0;i<N; i++) cout << ans[i]<<' ';
	
}
