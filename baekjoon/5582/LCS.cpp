#include<iostream>
using namespace std;
int lcs[4001][4001];
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	int ans=0;
	for(int i=0;i <a.size(); i++){
		for(int j=0; j<b.size(); j++){
			if(a[i]==b[j]) {
				lcs[i+1][j+1]=lcs[i][j]+1;
				ans=ans<lcs[i+1][j+1]? lcs[i+1][j+1]:ans;
			}
		}
	}
	cout << ans;
}
