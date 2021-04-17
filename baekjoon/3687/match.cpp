#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int numMatches[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vector< vector<int> > comb;
vector<int> c;

void getComb(int num){
	if(num==0) {
		comb.push_back(c);
		return ;
	}
	for(int i=0; i<10; i++){
		bool addNum=true;
		if(num-numMatches[i]<0) {
			addNum=false;
			continue;
		}else{
			num-=numMatches[i];
			c.push_back(i);
		}
		getComb(num);
		if(addNum){
			num+=numMatches[i];
			c.pop_back();
		}
	}
	return;
}

pair<vector<int> , vector<int> > getMinMax(){
	vector< vector<int> > maxCand;
	vector< vector<int> > minCand;
	int maxLen=0;
	int minLen=50;
	for(int i=0; i<comb.size(); i++){
		if (comb[i].size()>maxLen) maxLen=comb[i].size();
		if (comb[i].size()<minLen) minLen=comb[i].size();
	}
	for(int i=0; i<comb.size(); i++){
		if(comb[i].size()==minLen)
			minCand.push_back(comb[i]);
		if(comb[i].size()==maxLen)
			maxCand.push_back(comb[i]);
	}
	for(int i=0; i<maxCand.size(); i++){
		sort(maxCand[i].begin(), maxCand[i].end(), greater<int>());
	}
	for(int i=0; i<minCand.size(); ){
		sort(minCand[i].begin(), minCand[i].end());
		if(minCand[i].size()==1&&minCand[i][0]==0){
			minCand.erase(minCand.begin()+i);
			continue;
		}
		if (minCand[i][0]==0) {
			for(int j=0; j<minCand[i].size(); j++){
				if(minCand[i][j]!=0) {
					iter_swap(minCand[i].begin(), minCand[i].begin()+j);
					break;
				}
			}
		}
		i++;
	}
	vector<int> maxVec=maxCand[0];
	int maxIdx=0;
	for(int i=0; i<maxLen; i++ ){
		for(int j=0; j<maxCand.size();){
			if(maxCand[j][i]>maxVec[i]){
				maxCand.erase(maxCand.begin()+maxIdx);
				maxVec=maxCand[j-1];
				maxIdx=j-1;
			}else if( maxCand[j][i]<maxVec[i]){
				maxCand.erase(maxCand.begin()+j);
			}else{
				j++;
			}
		}
	}
	vector<int>minVec =minCand[0];
	int minIdx=0;
	for(int i=0; i<minLen; i++){
		for(int j=0; j<minCand.size();){
			if(minCand[j][i]<minVec[i]){
				minCand.erase(minCand.begin()+minIdx);
				minVec=minCand[j-1];
				minIdx=j-1;
			}else if(minCand[j][i] >minVec[i]){
				minCand.erase(minCand.begin()+j);
			}else{
				j++;
			}
		}
	}

	return make_pair(maxVec, minVec);

}

int main(){
	int tcs;
	cin >> tcs;
	vector<pair<vector<int>, vector<int> > > ans;
	for(int i=0; i<tcs; i++){
		int num;
		cin >> num;
		getComb(num);
		ans.push_back(getMinMax());
		comb.clear();
	}
	for(int i=0; i<tcs; i++){
		for(int j=0; j<ans[i].second.size();j++)
			cout << ans[i].second[j];
		cout <<' ';
		for(int j=0; j< ans[i].first.size(); j++)
			cout << ans[i].first[j];
		cout <<'\n';
	}
}

