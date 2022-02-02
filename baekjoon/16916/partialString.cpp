#include<iostream>
#include<vector>

using namespace std;

vector<int> preprocessing(string p){
	vector<int> pi(p.size());
	pi[0]=0;
	int j=0;
	for(int i=1; i<p.size(); i++){
		while(j>0 && p[i] != p[j]){
			j=pi[j-1];
		}
		if(p[i]==p[j]){
			j+=1;
			pi[i]=j;
		}else{
			pi[i]=0;
		}
	}
	return pi;
}

int main(void){
	string S, P;
	cin >> S;
	cin.ignore();
	cin >> P;
	int j=0, i=0;
	vector<int> kmp = preprocessing(P);
	int ans=0;
	while(i<S.size()){
		if(S[i]==P[j]){
			j++;
			i++;
			if(j==P.size()){
				ans=1;
				break;
			}
		}else{
			if(j!=0) j=kmp[j-1];
			else i++;
		}
	}
	cout << ans;
}
