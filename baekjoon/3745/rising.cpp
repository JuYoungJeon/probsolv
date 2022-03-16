#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int arr[100001];
int lis[100001];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	while(cin >> N){
		memset(arr, 0, sizeof(arr));
		memset(lis, 0, sizeof(lis));
		int idx=0;
		for(int i=1; i<=N; i++){
			cin >> arr[i];
		}
		for(int i=1; i<=N; i++){
			if(idx==0||arr[i]>lis[idx-1]) lis[idx++]=arr[i];
			else lis[lower_bound(lis, lis+idx, arr[i])-lis]=arr[i];
		}
		cout << idx-1<<'\n';
	}
}
