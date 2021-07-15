#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> tree;
vector<pair<int, int> > arr;

void updateTree(int N, int idx, int diff){
	while(idx<=N){
		tree[idx]+=diff;
		idx=idx+(idx&-idx);
	}
}

int getIdx(int N, int idx){
	int sum=0;
	while(idx>0){
		sum+=tree[idx];
		idx=idx-(idx&-idx);
	}
	return sum;
}

int main(void){
	int N;
	scanf("%d", &N);
	tree.resize(N+1);
	for(int i=0;i<N; i++){
		int t;
		scanf("%d", &t);
		arr.push_back(make_pair(t, i));
	}
	sort(arr.rbegin(), arr.rend());
	long long ans=0;
	for(auto& e: arr){
		ans+=getIdx(N, e.second);
		updateTree(N, e.second+1, 1);
	}
	printf("%lld", ans);
}
