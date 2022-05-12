#include<iostream>

using namespace std;

int A[10];
long long ans = 1e12+1;

void calTime(int N, int K){
	long long s=0;
	long long e=1e12+1;
	long long m= (s+e)/2;
	while(s<=e){
		m = (s+e)/2;
		long long nf=0;
		for(int i=0;i<N; i++){
			nf+=(m/A[i]);
		}
		if(nf<K){
			s = m+1;
		}else{
			ans = min(ans, m);
			e = m-1;
		}
	}

}

void dfs(int N, int K, int C){
	if(C==0){
		calTime(N, K);
		return ;
	}
	for(int i=0;i<N; i++){
		if(A[i]==1) {
			dfs(N, K, C-1);
		}else{
			A[i]-=1;
			dfs(N, K, C-1);
			A[i]+=1;
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K, C;
	cin >> N >> K >> C;
	for(int i=0; i<N ;i++){
		cin >> A[i];
	}
	dfs(N, K, C);
	cout << ans;
}
