#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(1){
		int N;
		cin >> N;
		if(N==0) break;
		vector<int> num;
		for(int i=0;i<N; i++){
			int t;
			cin >> t;
			num.push_back(t);
		}
		vector<int> cmb;
		for(int i=0;i<6; i++) cmb.push_back(1);
		for(int i=0;i<N-6; i++) cmb.push_back(0);
		do{
			for(int i=0;i<N; i++){
				if(cmb[i]==1){
					cout << num[i]<<' ';
				}
			}
			cout <<'\n';
		}while(prev_permutation(cmb.begin(), cmb.end()));
		cout <<'\n';
	}
}
