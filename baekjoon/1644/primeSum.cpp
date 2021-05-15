#include<cstdio>
#include<vector>
using namespace std;
int main(void){
	int N;
	scanf("%d", &N);
	vector<int> allNum(N+1, 1);
	vector<int> prime;
	int i=2;
	while(i<=N){
		int iter=2;
		if(allNum[i]==1) {prime.push_back(i);}
		else {i+=1; continue;}
		while(i*iter<=N){
			allNum[i*iter]=0;
			iter+=1;
		}
		i+=1;
	}
	int s=0, e=s;
	int ans=0;
	int sum=prime[s];
	while(s<prime.size()){
		if(sum==N) ans+=1;
		if(sum<N) {
			if(e+1==prime.size())break;
			e+=1; sum+=prime[e];}
		else {sum-=prime[s];s+=1;}
	}
	printf("%d", ans);
}
//Note: 에라토스테스의 체 -> 이미제거된 수는 continue(시간단축)nlogn
