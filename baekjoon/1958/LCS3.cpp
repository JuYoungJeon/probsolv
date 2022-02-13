#include<iostream>
#include<string>

using namespace std;

int LCS[101][101][101];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string A, B, C;
	cin >> A >> B >> C;

	for(int i=1; i<=A.size(); i++){
		for(int j=1; j<=B.size(); j++){
			for(int k=1; k<=C.size(); k++){
				if(A[i-1]==B[j-1]&&A[i-1]==C[k-1]) LCS[i][j][k]=LCS[i-1][j-1][k-1]+1;
				else{
					LCS[i][j][k]=max(LCS[i-1][j][k], LCS[i][j-1][k]);
					LCS[i][j][k]=max(LCS[i][j][k], LCS[i][j][k-1]);
				}
			}
		}
	}
	cout << LCS[A.size()][B.size()][C.size()];
}
