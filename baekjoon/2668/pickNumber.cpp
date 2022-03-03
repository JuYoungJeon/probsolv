#include<iostream>
#include<cstring>

using namespace std;

int arr[101];
int innode[101];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	memset(innode, 0, sizeof(innode));
	for(int i=1;i<=N; i++){
		cin >> arr[i];
		innode[arr[i]]+=1;
	}
	bool endCond=false;
	int ans=0;
	while(!endCond){
		ans=0;
		endCond=true;
		for(int i=1; i<=N; i++){
			if(innode[i]==0) {
				innode[arr[i]]-=1;
				innode[i]=-1;
				endCond=false;
			}
			if(innode[i]>0){
				ans+=1;
			}
		}
	}
	cout << ans<<'\n';
	for(int i=1; i<=N; i++){
		if(innode[i]>0) cout << i <<'\n';
	}
	
}
