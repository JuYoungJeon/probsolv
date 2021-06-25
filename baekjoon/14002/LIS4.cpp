#include<cstdio>
#include<vector>
using namespace std;
vector<pair<int, int> > lis;
vector<int> arr;
int main(void){
	int N;
	scanf("%d", &N);
	arr.push_back(0);
	for(int i=0; i<N; i++) {
		int ai; 
		scanf("%d", &ai);
		arr.push_back(ai);
	}
	int maxIdx=0, maxVal=0;
	lis.push_back(make_pair(0, 0));
	for(int i=1; i<=N; i++){
		int mv=0, mi=0;
		for(int j=i-1; j>0; j--){
			if(arr[j]>= arr[i])continue;
			if(lis[j].first>mv){
				mv=lis[j].first;
				mi=j;
			}
		}
		if(maxVal<mv+1) { maxVal=mv+1; maxIdx=i;}
		lis.push_back(make_pair(mv+1, mi));
	}
	printf("%d\n", maxVal);
	vector<int> ans;
	while(maxIdx>0){
		ans.push_back(arr[maxIdx]);
		maxIdx=lis[maxIdx].second;
	}
	for(int i=ans.size()-1; i>=0; i--) printf("%d ", ans[i]);
}
