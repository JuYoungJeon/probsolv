#include<iostream>
#include<cstring>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, ans=0; 
	int arr[1000001];
	int bal[1000000];
	cin >> N;
	memset(arr, 0, sizeof(arr));
	for(int i=0;i<N; i++){
		cin >> bal[i];
	}
	for(int i=0;i<N; i++){
		if(!arr[bal[i]]) ans+=1;
		else arr[bal[i]]--;
		arr[bal[i]-1]++;
	}
	cout << ans;
}
