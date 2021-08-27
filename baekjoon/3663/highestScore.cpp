#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	while(tc--){
		string name;
		cin >> name;
		int ans=0;
		bool fin=false;
		vector<int> idxes;
		int s = name.size();
		for(int i=0;i<s; i++){
			if(name[i]!='A') idxes.push_back(i);
			ans+=min(name[i]-'A','Z'-name[i]+1);
		}
		int minMove=s-1;
		if (idxes.size()==0){ cout << ans <<'\n'; continue;}
		minMove=min(minMove, idxes.back());
		minMove=min(minMove, s-idxes[0]);
		if(idxes.size()==1){
			minMove=min(idxes[0], s-idxes[0]);
		}
		for(int i=0; i<idxes.size()-1; i++){
			minMove=min(minMove, idxes[i]*2+s-idxes[i+1]);
		}
		for(int i=idxes.size()-1; i>0; i--){
			minMove=min(minMove, (s-idxes[i])*2+idxes[i-1]);
		}
		cout << minMove+ans<<'\n';
	}
}
//A만 있을경우, 한방향만 갔을때 끝이나 시작이 A로 이뤄진경우 고려
