#include<iostream>
#include<cstring>
#include<bitset>

using namespace std;

bitset<20> film[13];
int minT;
bool check(int D, int W, int K){
	bool succ=true;
	for(int i=0;i<W; i++){
		int cnt=1;
		for(int j=1; j<D; j++){
			if(film[j][i]==film[j-1][i]) cnt+=1;
			else cnt=1;
			if(cnt>=K) break;
		}
		if(cnt<K) return false;
	}
	return succ;
}
int dfs(int num, int idx, int D, int W, int K){
	if(idx==D+1) return K;
	if(minT<=num) return minT;
	if(check(D, W, K)) return minT=min(minT, num);
	minT=min(minT, dfs(num, idx+1, D, W, K));
	bitset<20> tmp = film[idx];
	film[idx].set();
	minT=min(minT, dfs(num+1, idx+1, D, W, K));
	film[idx].reset();
	minT=min(minT, dfs(num+1, idx+1, D, W, K));
	film[idx]=tmp;
	return minT;
}
int main(void){
	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++){
		int D, W, K;
		cin >> D>>W>>K;
		for(int i=0; i<D; i++){
			for(int j=0;j<W; j++){
				int tmp;
				cin >> tmp;
				if(tmp) film[i].set(j, true);
				else film[i].set(j, false);
			}
		}
		minT=K;
		minT= min(minT, dfs(0, 0, D, W, K));
		cout << minT<<'\n';;
	}
}
