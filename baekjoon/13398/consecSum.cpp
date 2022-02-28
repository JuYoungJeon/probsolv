#include<iostream>
#include<cstring>

using namespace std;

int arr[100001];
int sum[100001][2];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	sum[0][0]=arr[0];
	sum[0][1]=-2001;
	int ans=max(sum[0][0], sum[0][1]);
	for(int i=1; i<N; i++){
		sum[i][0]=max(sum[i-1][0]+arr[i], arr[i]);
		sum[i][1]=max(sum[i-1][1]+arr[i], sum[i-1][0]);
		ans=max(ans, sum[i][0]);
		ans=max(ans, sum[i][1]);
	}
	cout << ans;
}
