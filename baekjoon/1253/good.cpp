#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int arr[2000];
int check[2000];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(arr, 0, sizeof(arr));
	memset(check, 0, sizeof(check));
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	int ans=0;
	sort(arr, arr+N);
	for(int i=0;i<N-1; i++){
		for(int j=i+1; j<N; j++){
			int fnd = lower_bound(arr, arr+N, arr[i]+arr[j])-arr;
			while(fnd<N&&arr[i]+arr[j]==arr[fnd]&&!check[fnd]){
				if(fnd==i||fnd==j){
					fnd+=1;
					continue;
				}
				check[fnd]=1;
				ans+=1;
				fnd+=1;
			}
		}
	}
	cout << ans;
}
