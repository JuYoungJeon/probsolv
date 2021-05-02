#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int cd(int a, int b){
	if(b!=0) {
		return cd(b, a%b);
	}else
		return a;
}

int main(void){
	int n;
	scanf("%d", &n);
	int num[100];
	for(int i=0; i<n; i++){
		scanf("%d", &num[i]);
	}
	sort(num, num+n);
	int gcd=num[1]-num[0];
	for(int i=2; i<n; i++){
		gcd=cd(gcd, num[i]-num[i-1]);
	}
	vector <int> ans;
	for(int i=1; i*i<=gcd; i++){
		if(i==1)
			ans.push_back(gcd);
		else{
			if(gcd%i==0){
				ans.push_back(gcd/i);
				if((gcd/i)!=i) ans.push_back(i);
			}
		}
	}
	sort(ans.begin(), ans.end());
	for(auto it=ans.begin(); it!=ans.end(); it++){
		printf("%d ", *it);
	}
}
//Note : 유클리드 호재법을 사용하여 문제를 풀기
//1. Sort input numbers
//2. Compute the gcd of all numbers by computing the gcd of difference between the neighboring numbers
//3. Compute the divsors of the gc

