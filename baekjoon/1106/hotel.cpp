#include<iostream>
using namespace std;

int c[100001];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, C;
	cin >> C >> N;
	int ad[20][2];
	for(int i=0;i<N; i++){
		cin >> ad[i][0] >> ad[i][1];
	}
	int ans=1000001;
	for(int i=0; i<N; i++){
		for(int j=1; j<=100001; j++){
			if(j-ad[i][0]<0) continue;
			c[j]=max(c[j], c[j-ad[i][0]]+ad[i][1]);
		}
	}
	for(int i=1; i<100001; i++){
		if(c[i]>=C) {
			cout << i;
			break;
		}
	}
}
