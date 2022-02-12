#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int LCS[1001][1001];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string A, B;
	cin >> A >> B;

	for(int i=1;i<=A.size(); i++){
		LCS[0][i]=LCS[0][i-1]+1;
	}
	for(int i=1; i<=B.size(); i++){
		LCS[i][0]=LCS[i-1][0]+1;
	}

	for(int i=1; i<=B.size(); i++){
		for(int j=1; j<=A.size(); j++){
			if(A[j-1]==B[i-1]) LCS[i][j]=LCS[i-1][j-1];
			else{
				LCS[i][j]=min(LCS[i-1][j-1], LCS[i-1][j]);
				LCS[i][j]=min(LCS[i][j], LCS[i][j-1]);
				LCS[i][j]+=1;
			}
		}
	}
	cout << LCS[B.size()][A.size()];
}
