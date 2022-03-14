#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

char path[300000];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, B, W;
	cin >> N >> B>> W;
	
	for(int i=0;i<N; i++){
		cin >> path[i];
	}
	int ans=0;
	int s=0, e=0;
	int nw=0, nb=0;
	while(e<N){
		if(path[e]=='B') nb++;
		else nw++;
		if(nb>B){
			while(nb>B){
				if(path[s]=='B')nb--;
				else nw--;
				s++;
			}
		}
		if(nw>=W) ans=max(ans, e-s+1);
		e++;
	}
	cout << ans;
}
