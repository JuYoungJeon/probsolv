#include<iostream>
using namespace std;
int arr[100001];
int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	for(int i=0;i<N; i++){
		cin >> arr[i];
	}
	int s=0, e=N-1; 
	int ans =0;
	while(s<e){
		ans=max(ans, min(arr[s], arr[e])*(e-s-1));
		if(arr[s]<arr[e]) s+=1;
		else e-=1;
	}
	cout << ans;

}
