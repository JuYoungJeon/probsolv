#include<iostream>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	ll n, k;
	ll arr[200001];
	cin >> n >> k;
	for(int i=0;i<n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	ll minTime=k;
	for(int i=1; i<n; i++){
		ll as=arr[0]*i;
		ll bs=arr[i]*(n-i);
		ll ret ;
		if(k%(as+bs)!=0) ret=(k/(as+bs))+1;
		else ret = (k/(as+bs));
		minTime=min(minTime, ret);
	}
	cout << minTime;
}
//NOTE: ll에서 나눌때 그냥 나눠서 ceil()사용하면 overflow일어날수있음! 
//=>mod로 divisible한지 확인하고 아니면 +1
