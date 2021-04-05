#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

struct syn{
	vector<int> start;
	vector<int> link;
	int start_s;
	int link_s;
};

int synergy[20][20];
vector <syn> sortedSyn;

int main(){
	int n;
	cin >> n;
	for (int i=0; i< n; i++){
		for(int j=0; j<n; j++){
			cin >> synergy[i][j];
		}
	}

	vector<bool> comb(n);
	fill(comb.begin(), comb.begin()+(n/2), true);
	int minDiff=99*n;
	do{
		syn newPair=syn();
		for (int i=0; i<n; i++){
			if(comb[i]){
				for(int j=0; j<newPair.start.size(); j++){
					newPair.start_s+=synergy[i][newPair.start[j]]+synergy[newPair.start[j]][i];
				}
				newPair.start.push_back(i);
			}else{
				for(int j=0; j<newPair.link.size(); j++){
					newPair.link_s+=synergy[i][newPair.link[j]]+synergy[newPair.link[j]][i];
				}
				newPair.link.push_back(i);
			}
		}
		sortedSyn.push_back(newPair);
		minDiff= min(minDiff, abs(newPair.start_s-newPair.link_s));
	}while(prev_permutation(comb.begin(), comb.end()));
	cout << minDiff; 

}
