#include<iostream>
#include<cmath>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int A, B;
	cin >> N;
	for(int i=0;i<N; i++){
		int t;
		cin >> t;
		if(i==0) A=t;
		if(i==N-1) B=t;
	}
	N=N-2;
	if(A>B){
		int t = A-B;
		A=A-min(N, t);
		N=max(N-t, 0);
	}else if(B>A){
		int t = B-A;
		B=B-min(N, t);
		N=max(N-t, 0);
	}
	if(A!=B||N==0){
		cout << max(A, B);
	}else{
		N-=1;
		cout << max(A, B)-N/2-1;
	}
}
