#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
int arr[15];
int check[15];
int N, L, R, X;
int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N>>L>>R>>X;
	for(int i=0;i<N; i++) cin>> arr[i];
	sort(arr, arr+N);
	int allp=1<<(N);
	int ans=0;
	for(int i=0;i<allp; i++){
		bitset<15> bs(i);
		int minval=arr[N-1], maxval=arr[0];
		int cnt=0;
		int sum=0;
		for(int j=0;j<N; j++){
			if(bs[j]) {
				sum+=arr[j];
				minval=min(minval, arr[j]);
				maxval=max(maxval, arr[j]);
				cnt+=1;
			}
		}
		if(cnt>1&&sum>=L&&sum<=R&&maxval-minval>=X) ans+=1;
	}
	cout << ans;
}
