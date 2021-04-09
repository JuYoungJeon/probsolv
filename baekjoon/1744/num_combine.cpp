#include <iostream>
#include <algorithm>

using namespace std;

int nums[10000]={0};

bool desc(int a, int b){
	return a>b;
}

int main(void){
	int n;
	cin >> n;

	for (int i=0; i<n; i++){
		cin >> nums[i];
	}
	sort(nums, nums+n, desc);
	int ans=0;
	int idx=0;
	while(nums[idx]>0){
		if(idx==n-1) {
			ans+=nums[n-1];
			break;
		}
		if(nums[idx+1]<=0){
			ans+=nums[idx];
			break;
		}
		if(nums[idx]*nums[idx+1]>(nums[idx]+nums[idx+1])) ans+=nums[idx]*nums[idx+1];
		else{
			ans+=nums[idx];
			ans+=nums[idx+1];
		}
		idx+=2;
	}
	int idx_rev=n-1;
	while(nums[idx_rev]<0){
		if(idx_rev==0){
			ans+=nums[idx_rev];
			break;
		}
		if(nums[idx_rev-1]>0){
			ans+=nums[idx_rev];
			break;
		}
		if(nums[idx_rev]*nums[idx_rev-1]>(nums[idx_rev]+nums[idx_rev-1])) ans+=nums[idx_rev]*nums[idx_rev-1];
		else{
			ans+=nums[idx_rev];
			ans+=nums[idx_rev-1];
		}
		idx_rev-=2;
	}
	cout << ans;
}
