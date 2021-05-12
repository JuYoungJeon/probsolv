#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(void){
	int N;
	vector<int> nums;
	scanf("%d", &N);
	for(int i=0;i<N; i++){
		int t;
		scanf("%d", &t);
		nums.push_back(t);
	}
	sort(nums.begin(), nums.end());
	int s=0, e=N-1;
	int minV=abs(nums[s]+nums[e]);
	int minS=s, minE=e;
	while(s<e){
		if(minV>abs(nums[s]+nums[e])){
			minS=s;
			minE=e;
			minV=abs(nums[s]+nums[e]);
		}
		if(s<e-1&&abs(nums[s]+nums[e-1])<abs(nums[s+1]+nums[e])) e--;
		else s++;
	}
	printf("%d %d", nums[minS], nums[minE]);

}
//Note: move (line:25)부분에 nums[s]+num[e]>0해도됨
