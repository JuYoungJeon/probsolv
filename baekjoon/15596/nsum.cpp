#include<cstdio>
#include<vector>
using namespace std;
long long sum(vector<int> &a){
	long long ans=0;
	for(auto &t: a){
		ans+=t;
	}
	return ans;
}
int main(void){
	vector<int> a{0,1,2,3,4,5,6,7,8,9,10};
	printf("%lld", sum(a));
}
