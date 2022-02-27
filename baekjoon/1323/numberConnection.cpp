#include<iostream>
#include<cstring>

using namespace std;

int rem[100001];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	long long nIdx=1;
	int t=N;
	memset(rem, 0, sizeof(rem));
	while(t!=0) {
		nIdx*=10;
		t/=10;
	}
	int ans=1;
	long long r = N%K;
	rem[r]=1;
	while(r!=0){
		r= (r*nIdx+N)%K;
		if(rem[r]){
			ans=-1;
			break;
		}
		rem[r]=1;
		ans+=1;
	}
	cout << ans;
}
