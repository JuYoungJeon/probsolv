#include <iostream>

using namespace std;

int main(void){
	int n, m, k;
	cin >> n >> m >> k;

	int left=0;
	if(n>2*m){
		left+=(n-2*m);
		n-=left;
	}else if(n<2*m){
		left+=(m-(n/2));
		m-=left;
		if (n%2>0) left+=1;
	}
	k-=left;
	int team=m;
	if(k>0){
		team-=k/3;
		if (k%3>0) team-=1;
	}
	cout << team;
}
