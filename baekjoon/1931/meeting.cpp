#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair <int, int> > meetings;

int greedy(int n){
	int prevEnd=meetings[0].first;
	int ans=1;
	for(int i=1; i<n; i++){
		if(meetings[i].second>=prevEnd){
			ans+=1;
			prevEnd=meetings[i].first;
		}
	}
	return ans;
}




int main(void){
	int n;
	cin >> n;

	for(int i=0; i< n; i++){
		int start, end;
		cin >> start >> end;
		meetings.push_back(make_pair(end, start));
	}
	sort(meetings.begin(), meetings.end());
	cout << greedy(n);

}
