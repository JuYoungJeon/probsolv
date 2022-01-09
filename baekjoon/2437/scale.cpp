#include<iostream>
#include<algorithm>

using namespace std;

int given[1000];
int N;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i=0;i<N; i++){
		cin >> given[i];
	}
	sort(given, given+N);
	int sum=0, ans=sum+1;
	for(int i=0;i<N; i++){
		if(ans<given[i]) break;
		sum+=given[i];
		ans=sum+1;
	}
	cout << ans;
}
