#include<iostream>
#include<algorithm>
using namespace std;
long long heights[100000];
long long getMax(int ls, int le, int rs, int re){
	long long minh=min(heights[le], heights[rs]);
	int l=le, r=rs;
	long long ans=minh*2;
	while(l>ls||r<re){
		if(r<re&&(l==ls||heights[r+1]>heights[l-1])){
			r+=1;
			minh=min(minh, heights[r]);
		}else{
			l-=1;
			minh=min(minh, heights[l]);
		}
		ans=max(ans, minh*(r-l+1));
	}
	return ans;
}

long long divideConquer(int s, int e){
	if(s==e) return heights[s];
	long long mid= (s+e)/2;
	long long lmax=divideConquer(s, mid);
	long long rmax=divideConquer(mid+1, e);
	long long mmax=getMax(s, mid, mid+1, e);
	long long ans = max(lmax, rmax);
	ans=max(ans, mmax);
	return ans;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(1){
		int n;
		cin >> n;
		if (n==0) break;
		for(int i=0; i<n; i++){
			cin >> heights[i];
		}
		cout << divideConquer(0,n-1) <<'\n';
	}
}
