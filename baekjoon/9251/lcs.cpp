#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int adp[1001][1001];
int main(void){
	memset(adp, 0, sizeof(adp));
	string a, b;
	cin >> a >> b;
	for(int i=1; i<=a.size(); i++){
		for(int j=1; j<=b.size(); j++){
			if(a[i-1]!=b[j-1]) adp[i][j]=max(adp[i-1][j], adp[i][j-1]);
			else adp[i][j]=adp[i-1][j-1]+1;
		}
	}
	printf("%d", adp[a.size()][b.size()]);
}
//LCS알고리즘
